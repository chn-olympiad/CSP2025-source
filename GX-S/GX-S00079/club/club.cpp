#include<bits/stdc++.h>
using namespace std;
int t;
int n=0,f[100010][4],ans,st[100010][4];
void dfs(int x,int a,int b,int c,int k){
	if(k==n){
		ans=max(ans,x);
		return ;
	}
	if(a+1<=n/2){
		dfs(x+st[k+1][1],a+1,b,c,k+1);
	}
	if(b+1<=n/2){
		dfs(x+st[k+1][2],a,b+1,c,k+1);
	}
	if(c+1<=n/2){
		dfs(x+st[k+1][3],a,b,c+1,k+1);
	}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t){
		t--;
        cin>>n;
        ans=0;
        memset(f,0,sizeof(f));
        memset(st,0,sizeof(st));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
				cin>>st[i][j];
			}
        }
		dfs(st[1][1],1,0,0,1);
		dfs(st[1][2],0,1,0,1);
		dfs(st[1][3],0,0,1,1);
        cout<<ans<<endl;
    }
    return 0;
}
