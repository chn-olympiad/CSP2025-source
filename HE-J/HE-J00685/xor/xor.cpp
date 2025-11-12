#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;

int n,k,ans;
int a[N],dp[N],p[N];
bool f,flag;

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		if(a[i]>1) flag=true;
	}
	if(!flag&&n>1000&&k<=1){
		int s=0,t=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) s++;
			else t++;
		}
		if(k==1) cout<<s;
		else{
			int m=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					m++;
					if(m==2) t++,m=0;
				}
				else m=0;
			}
			cout<<t;
		} 
		return 0;
	}
	for(int i=1;i<=n;i++) p[i]=p[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			int l=p[i]^p[j];
			if(l==k){
				dp[i]=max(dp[i],dp[j]+1);
			}
			else dp[i]=max(dp[i],dp[i-1]);
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans; 
	return 0;
}
// 5 3 6 4 2 1 3
/*
4 3 2 1 0 3
*/
/*
4 2 2 1 0 3
*/
/*
5 1 1 4 1 3 1
*/



