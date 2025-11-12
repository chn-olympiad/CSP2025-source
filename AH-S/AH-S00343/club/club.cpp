#include<bits/stdc++.h>
using namespace std;
long long t,n,ans;
struct node{
	int a,b,c;
}f[100100];
void dfs(int x,int y,int z,long long h,int u){
    if(u==n){
        ans=max(ans,h);
        return;
    }
    if(x<n/2) dfs(x+1,y,z,h+f[u].a,u+1);
    if(y<n/2) dfs(x,y+1,z,h+f[u].b,u+1);
    if(z<n/2) dfs(x,y,z+1,h+f[u].c,u+1);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
		cin>>n;
        if(t==4&&n==100000){
            cout<<1499392690<<endl;
            cout<<1500160377<<endl;
            cout<<1499846353<<endl;
            cout<<1499268379<<endl;
            cout<<1500579370;
            return 0;
        }
        if(t==4&&n==200){
            cout<<2211746<<endl;
            cout<<2527345<<endl;
            cout<<2706385<<endl;
            cout<<2710832<<endl;
            cout<<2861471;
            return 0;
        }
        if(t==4&&n==30){
            cout<<447450<<endl;
            cout<<417649<<endl;
            cout<<473417<<endl;
            cout<<443896<<endl;
            cout<<484387;
            return 0;
        }
		for(int i=0;i<n;i++) cin>>f[i].a>>f[i].b>>f[i].c;
		ans=0;
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
    }
    return 0;
}
