#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;
int a[N],d[N];
bool b[N];
int cnt;
int n;
void dfs(int dep,int k,int pos){
    if(k>dep){
        int sum=0;
        for(int i=1;i<dep;i++){
            sum+=d[i];
            if(sum>d[dep])
                break;
        }
        if(sum>d[dep]){
            cnt++;
        }
        return;
    }
    for(int i=pos+1;i<=n;i++){
        if(!b[pos]){
            d[k]=a[i];
            b[pos]=1;
            dfs(dep,k+1,i);
            b[pos]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        dfs(i,1,0);
    }
    cout<<cnt<<'\n';
    return 0;
}
