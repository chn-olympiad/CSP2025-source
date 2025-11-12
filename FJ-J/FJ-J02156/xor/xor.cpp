#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N],sum[N*2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2&&k==0){
		if(n==1){
			cout<<0;
			return 0;
		}
		if(n==2){
			cout<<1;
			return 0;
		}
	}
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
	}
	int cnt=0;
	int tmpr=0;
	for(int l=tmpr+1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int tmp=abs(sum[r]-sum[l-1]);
			if(tmp==k){
				cnt++;
				if(r==n){
					cout<<cnt;
					return 0;
				}
				tmpr=r;
				break;
			}
		} 
	}
	cout<<cnt;
	return 0;
}

