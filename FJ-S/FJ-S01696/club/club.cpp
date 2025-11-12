#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[101000][4];
ll n,t,ans;
ll inperson[4];
ll half[101000][4];
priority_queue<ll>q1,q2,q3;
void dfs(ll step ,ll tot){
	if(step==n+1){
		if(tot>ans) ans=tot;
		return ;
	}
	for(int i=1;i<=3;i++){
		if(inperson[i]<n/2){
			tot+=a[step][i];
			inperson[i]++;
			dfs(step+1,tot);
			tot-=a[step][i];
			inperson[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=-1;
		memset(inperson,0,sizeof(inperson));
		if(n<=10) dfs(1,0);
		else{
			for(int i=1;i<=n/2;i++){
				ans+=q1.top();
				q1.pop();
				ans+=q2.top();
				q2.pop();
				ans+=q3.top();
				q3.pop();
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
