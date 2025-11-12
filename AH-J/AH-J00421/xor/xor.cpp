#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N],sum[N];
long long n,k,flg;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flg=1;
	}sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]&a[i];
	}if(!flg){
		if(k==0){
			cout<<n/2;
		}else if(k==1){
			cout<<n;
		}else cout<<0;
	}else{
		long long cnt=0,s=a[1];
		for(int i=2;i<=n;i++){
			if(s==k){
				cnt++;
				s=a[i];
			}else s&=a[i];
		}if(s==k)cnt++;
		cout<<cnt;
	}
	return 0;
}
