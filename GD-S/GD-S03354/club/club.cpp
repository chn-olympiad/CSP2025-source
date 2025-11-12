#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100005][4],ans,u[100005];
void dfs(int x,int sum,int c1,int c2,int c3){
	if(c1>n/2||c2>n/2||c3>n/2)return ;
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	dfs(x+1,sum+a[x][1],c1+1,c2,c3);
	dfs(x+1,sum+a[x][2],c1,c2+1,c3);
	dfs(x+1,sum+a[x][3],c1,c2,c3+1);
}
void dfsb(int x,int sum,int c1,int c2){
	if(c1>n/2||c2>n/2)return ;
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	dfsb(x+1,sum+a[x][1],c1+1,c2);
	dfsb(x+1,sum+a[x][2],c1,c2+1);
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		int cc=0,bc=0;
		int l=0;
        for(int i=1;i<=n;i++){
        	cin>>a[i][1]>>a[i][2]>>a[i][3];
        	if(a[i][2]==a[i][3]&&a[i][2]==0){
        		cc++;
			}
			else if(a[i][3]==0){
				bc++;
			}
			l++;
			u[l]=max(a[i][1],max(a[i][2],a[i][3]));
		}
		if(cc>=50){
		   sort(u+1,u+1+l,cmp);	 
		   for(int i=1;i<=n/2;i++){
		   	   ans+=u[i];
		   }
		}
		else if(bc>=50){
			dfsb(1,0,0,0);
		}
		else{
			//cout<<"asd";
			dfs(1,0,0,0,0);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
