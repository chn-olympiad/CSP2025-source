#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5;
ll n,k,ans,sum;
ll a[N+100],qi[N+100],dp[N+100],zuih[N+100];
bool g;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) qi[i]=a[i];
		else qi[i]=(qi[i-1]^a[i]);
		if(a[i]>1) g=1;
	} 
	if(n<=1000){
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ll cnt=0;
				for(int f=1;f<i;f++){
					cnt=max(cnt,dp[f]);
				} 
				if(((qi[i-1]^qi[j])==k&&i-1>0)||(i==1&&qi[j]==k)) cnt++;
				dp[j]=max(dp[j],cnt);
				ans=max(ans,dp[j]);
			}
		}
		cout<<ans<<"\n";
	}
	else if(!g){
		if(k==0){
			ll cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++,cnt=0;
				else cnt++;
				if(cnt==2) ans++,cnt=0;
			}
		}	
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
		}cout<<ans<<"\n";
	}
	else{
		ll len=0;
		for(int i=1;i<=n;i++){
			bool gcnt=0;
			for(int j=1;j<=len;j++){
				zuih[j]=(zuih[j]^a[i]);
				if(zuih[j]==k){
					gcnt=1;
					break;
				}
			} 
			if(gcnt){
				ans++;
				len=0;
			}
			else{
				len++;
				zuih[len]=a[i];
				if(a[i]==k) ans++,len=0;
			}
		} cout<<ans<<"\n";
	}
	return 0;
} /*
4 3
2 1 0 3
*/

