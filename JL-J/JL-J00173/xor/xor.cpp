#include<bits/stdc++.h>
#define MAXN 500010
using namespace std;
int n,k,ans,fans;
vector<int>vx(MAXN);
map<pair<int,int>,int>dv;

//int xor(int x,int y){
//    return (x&!y)|(!x&y);
//}
/*
void dfs(int p){
    if (p>n){
        fans=ans;
        return;
    }
//    if (dv[(pair){p,l}])return dv[(pair){p,l}];
    int tmp=0;
    for (int i=0;i<=n-p;i++){
        if (dv[(pair){p,i}]){
            ans++;
            dfs(p+i+1);
            ans--;
        }
        tmp=xor(tmp,vx[p+i]);
        if (tmp==k){

            ans++;
            dfs(p+i+1);
            ans--;
        }
    }
}
*/
int dfs(int p,int l){
    if (p+l>n||dv[(pair<int,int>){p,l}]==-1)return 0;
    if (dv[(pair<int,int>){p,l}])return dv[(pair<int,int>){p,l}];
    int tmp=0,ta=0;
    for (int i=0;i<=l;i++){
        tmp=tmp xor vx[p+i];
    }
    tmp=(tmp==k);
    for (int i=0;i<=n-p-l;i++){
        ta=max(ta,dfs(p+l+1,i));
    }
//    cout<<p<<" "<<l<<" "<<tmp<<" "<<ta+tmp<<endl;
    if (ta+tmp==0){
        dv[(pair<int,int>){p,l}]=-1;
        return 0;
    }
    return dv[(pair<int,int>){p,l}]=ta+tmp;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>vx[i];
    }
    for (int i=0;i<n;i++){
        fans=max(fans,dfs(1,i));
    }
    cout<<fans;
}
