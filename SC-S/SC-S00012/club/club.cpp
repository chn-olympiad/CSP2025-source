#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int t,n,ans;
int a[N][5],b[N];
void dfs(int x,int cn1,int cn2,int cn3,int sum){
	if(cn1>n/2||cn2>n/2||cn3>n/3) return;
	if(x==n+1){
		ans=max(ans,sum);return;
	}
	dfs(x+1,cn1+1,cn2,cn3,sum+a[x][1]);
	dfs(x+1,cn1,cn2+1,cn3,sum+a[x][2]);
	dfs(x+1,cn1,cn2,cn3+1,sum+a[x][3]);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		bool fl1,fl2;fl1=fl2=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2&&a[i][j]) fl1=0;
				if(j==3&&a[i][j]) fl2=0;
			}
		if(fl1&&fl2){
			for(int i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+n+1);
			for(int i=1;i<=n/2;i++) ans+=b[i];
		}	
		else if(fl2){
			priority_queue<pair<int,int>>q1,q2; 
			for(int i=1;i<=n;i++){
				if(a[i][1]>a[i][2]){
					q1.push({a[i][1],i});
					ans+=a[i][1];
				}
				else{
					q2.push({a[i][2],i});
					ans+=a[i][2];
				}
			}
			if(q1.size()>q2.size()){
				while(q1.size()>q2.size()){
					auto t=q1.top();q1.pop();
					ans-=t.first;
					q2.push({a[t.second][2],t.second});
					ans+=a[t.second][2];
				}
			}
			if(q1.size()<q2.size()){
				while(q1.size()<q2.size()){
					auto t=q2.top();q2.pop();
					ans-=t.first;
					q1.push({a[t.second][1],t.second});
					ans+=a[t.second][1];
				}
			}
			
		}
		else dfs(1,0,0,0,0);
		cout<<ans<<endl; 
	}
}