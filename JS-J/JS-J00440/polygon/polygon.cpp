#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,mod=998244353;
int n,a[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=7;j<=pow(2,n)-1;j++){
		int sum=0,maxx=0,x=j,cnt=1;
		while(x!=0){
			if(x%2==1){
				sum+=a[n-cnt+1];
				//cout<<a[n-cnt+1]<<' ';
				maxx=max(maxx,a[n-cnt+1]);
			}
			x/=2;
			cnt++;
		}
		//cout<<'\n';
		if(sum>2*maxx){
			ans++;
			ans=ans%mod;
		}
	}
	cout<<ans;
	return 0;
}
