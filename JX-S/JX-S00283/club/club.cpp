#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int n2;
int a[100001],b[100001],c[100001];
int maxn=-1;
void dfs(int p,int na,int nb,int nc,int res){
    if((na+nb+nc)==n&&p==(n+1)){
        maxn=max(maxn,res);
        return ;
    }
    if(na>n2){
        return ;
    }
    if(nb>n2){
        return ;
    }
    if(nc>n2){
        return ;
    }
    if((na+nb+nc)>n){
        return ;
    }
    if(na<n2){
        dfs(p+1,na+1,nb,nc,res+a[p]);
    }
    if(nb<n2){
        dfs(p+1,na,nb+1,nc,res+b[p]);
    }
    if(na<n2){
        dfs(p+1,na,nb,nc+1,res+c[p]);
    }
}
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);	
    int t;
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        maxn=-1;
        cin>>n;
        n2=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        dfs(1,0,0,0,0);
        cout<<maxn<<endl;
    }
    return 0;
}
/*
3
4 
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/