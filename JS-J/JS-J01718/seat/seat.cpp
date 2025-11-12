#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> a(n*m+1);
    for(int i=1;i<=n*m;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a.begin()+1,a.end(),greater<pair<int,int>>());
    int w=1;
    for(;w<=n*m;w++) if(a[w].second==1) break;
    int s=w/n,t=w%n;
    if(t==0){
        if(s&1) cout<<s<<' '<<m<<'\n';
        else cout<<s<<' '<<0<<'\n';
    }else{
        if(s&1) cout<<s+1<<' '<<m-t+1<<'\n';
        else cout<<s+1<<' '<<t<<'\n';
    }
}