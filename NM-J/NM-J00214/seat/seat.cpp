#include<bits/stdc++.h>
using namespace std;
int n,m,ming;
int a[110];
int f[12][12];
int maxn,l=1;
bool cmp(int x,int y){
    return x>y;
}
void dfs(int x,int y){
    while(f[n][m]==0){
    	if (maxn==ming){
    		cout<<y<<" "<<x;
    		return;
		}
        f[x][y]=maxn;
        if(x+1>n && y%2==1)y++;
        else if (x-1<1 && y%2==0)y++;
        else if (y%2==1)x++;
        else if (y%2==0)x--;
        maxn=a[++l];
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    ming=a[1];
    sort(a+1,a+n*m+1,cmp);
	maxn=a[1];
    dfs(1,1);
    return 0;
}
