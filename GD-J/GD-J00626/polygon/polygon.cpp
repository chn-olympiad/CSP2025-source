#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,a[1000005],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<(1<<n);i++){
		int cnt=0,maxn=0;
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				cnt+=a[j+1];
				maxn=max(maxn,a[j+1]);
			}
		}
		if(cnt>maxn*2) sum++;
	}
	cout<<sum;
	return 0;
}
