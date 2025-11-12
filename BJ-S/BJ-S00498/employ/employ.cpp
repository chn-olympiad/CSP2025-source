#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=998244353;
int n,m,ans=0;
string s;
vector<int> vv;
vector<int> v;
bool visit[10]={0};
bool suan(){
    int guo=0,go=0;
   // for(int i=1;i<=n;i++){
   //     cout<<vv[i-1]<<" ";
    //}
    //cout<<endl;
    for(int i=1;i<=n;i++){
      //  cout<<i<<": "<<s[i]<<" "<<v[vv[i-1]-1]<<endl;
        if(s[i]=='1'&&v[vv[i-1]-1]>go){
            guo++;
        }
        else{
            go++;
        }
    //<<guo<<" "<<go<<endl;
    }
    //cout<<guo<<" "<<go<<endl;
    return guo>=m;
}
void qpl(int x){
    if(x==n){
        if(suan()){
            ans++;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            visit[i]=true;
            vv.push_back(i);
            qpl(x+1);
            visit[i]=false;
            vv.pop_back();
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > q;

    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        pair<int,int> pp;
        pp.first=a;
        pp.second=i;
        q.push(pp);
    }
   // int go=0;
   // while(!q.empty()){
   //     int k=q.top().first;
   //     if(k<=go){
   //         go++;
    //        q.pop();
   //     }
   //     else{
   //         break;
   //     }
   // }
    //=q.size();
    while(!q.empty()){
        v.push_back(q.top().first);
        q.pop();
    }
    if(s.find('0')==-1){
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=inf;
        }
        cout<<ans;
    }
    else{
        qpl(0);
        cout<<ans;
    }
}
