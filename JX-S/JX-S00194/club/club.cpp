#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,x[N],y[N],z[N],k,ans,T;
void dfs(int p,int cx,int cy,int cz,int sum){
	if(p>n){
		ans=max(ans,sum);
		//cout<<cx<<" "<<cy<<" "<<cz<<" "<<sum<<'\n';
		return ;
	}
	if(cx<k&&x[p])dfs(p+1,cx+1,cy,cz,sum+x[p]);
	else if(cx<k&&!x[p])dfs(p+1,cx,cy,cz,sum);
	if(cy<k&&y[p])dfs(p+1,cx,cy+1,cz,sum+y[p]);
	else if(cy<k&&!y[p])dfs(p+1,cx,cy,cz,sum);
	if(cz<k&&z[p])dfs(p+1,cx,cy,cz+1,sum+z[p]);
	else if(cz<k&&!z[p])dfs(p+1,cx,cy,cz,sum);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		k=n/2;
		bool f=0,f1=0,f2=0;
		int cc=0;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
			if(x[i])f=1;
			if(z[i])f2=1;
			if(y[i])f1=1;
		}
		if(!f1&&!f2){
			sort(x+1,x+1+n);
			for(int i=n;i>=1;i--){
				cc++;
			ans+=x[i];
			if(cc>=k)break;
			}
			cout<<ans<<'\n';
			ans=0;
			continue;
		}
		if(!f1&&!f){
			sort(z+1,z+1+n);
			for(int i=n;i>=1;i--){
				cc++;
			ans+=z[i];
			if(cc>=k)break;
			}
			cout<<ans<<'\n';
			ans=0;
			continue;
		}if(!f&&!f2){
			sort(y+1,y+1+n);
			for(int i=n;i>=1;i--){
				cc++;
			ans+=y[i];
			if(cc>=k)break;
			}
			cout<<ans<<'\n';
			ans=0;
			continue;
		}
		dfs(0,0,0,0,0);
		cout<<ans<<"\n";
		ans=0;
		for(int i=1;i<=n;i++){
			x[i]=y[i]=z[i]=0;
		}
	}
	return 0;
}
