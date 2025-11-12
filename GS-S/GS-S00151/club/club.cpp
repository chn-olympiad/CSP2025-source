#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll arr[10005][3]={};

ll res,a,b,c,n;

void dfs(ll now,ll o){
    if(o==-1){
        res=max(res,now);
        return ;
    }
    if(a<n/2){
        a++;
        dfs(now+arr[o][0],o-1);
        a--;
    }
    if(b<n/2){
        b++;
        dfs(now+arr[o][1],o-1);
        b--;
    }
    if(c<n/2){
        c++;
        dfs(now+arr[o][2],o-1);
        c--;
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(ll i=0;i<n;i++){
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        }
        res=0,a=0,b=0,c=0;
        dfs(0,n-1);
        cout<<res<<"\n";
    }
    return 0;
}
