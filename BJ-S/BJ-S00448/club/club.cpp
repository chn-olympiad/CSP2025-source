#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node{
    int a,b,c;
}st[1000000];
struct node2{
    int l,sc;
};
int ansn=0,vis[1000000];
void dfs(node2 x,node2 y,node2 z,int k){
    if(k==n+1){
		cout << x.l << ' ' << y.l <<  ' ' << z.l << endl;
        ansn=max(ansn,x.sc+y.sc+z.sc);
        return;
    }
    for(int i=1;i<=n;i++){
        if(x.l<n/2 and vis[i]==0){
			vis[i]=1;
            dfs({x.l+1,x.sc+st[i].a},y,z,k+1);
            vis[i]=0;
        }
        if(y.l<n/2 and vis[i]==0){
			vis[i]=1;
            dfs(x,{y.l+1,y.sc+st[i].b},z,k+1);
            vis[i]=0;
        }
        if(z.l<n/2 and vis[i]==0){
			vis[i]=1;
            dfs(x,y,{z.l+1,z.sc+st[i].c},k+1);
            vis[i]=0;
        }
    }
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n;
        for(int j=1;j<=n;j++){
            cin >> st[j].a >> st[j].b >> st[j].c;
        }
        dfs({0,0},{0,0},{0,0},1);
        cout << "ans" << ansn << endl;
        ansn=0;
    }
	fclose(stdin);
	fclose(stdout);
    return 0;
}