#include<bits/stdc++.h>
using namespace std;
int n,a[10005],ans=0,cnt=0,maxn=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			for(int k=j;k<=j+i;k++){
				maxn=max(a[k],maxn);
				cnt+=a[k];
			}
			if(cnt>2*maxn)ans++;
			ans%=998244353;
			cnt=0;
		}
	}
	cout<<ans*3%998244353;
	return 0;
}
