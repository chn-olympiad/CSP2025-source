#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n,a[5010];
int b[5010];
ll cntt=0;
map<int,map<ll,map<int,bool> > > m;
map<int,int> Cnt;
void dfs(int now,ll sum,int maxs,int cnt){
    if(cnt>2){
        if(sum>(maxs*2)&&m[cnt][sum][maxs]==0)
        {//
            
            m[cnt][sum][maxs]=1;
            int k=1;
            for(int i=0;i<cnt;i++){
                k*=Cnt[ b[i] ];
            }
            cntt+=(sum>(maxs*2))*k;
        }
    }
    if(now>n){
        return ;
    }
    b[cnt]=a[now];
    dfs(now+1,sum+a[now],a[now],cnt+1);
    dfs(now+1,sum,maxs,cnt);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n&&cin>>a[i];i++)Cnt[ a[i] ]++;
    sort(a+1,a+1+n);
    dfs(1,0,0,0);
    cout<<cntt;
    return 0;
}
//1 2 3 4