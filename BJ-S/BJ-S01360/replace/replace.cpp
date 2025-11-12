#include<bits/stdc++.h>
using namespace std;
int n,m,rpm;
string x,y;
struct rp{
    int len;
    string s1,s2;
}a[200010];
bool cmp(rp t1,rp t2){return t1.len<t2.len;}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i].s1>>a[i].s2,a[i].len=a[i].s1.size(),rpm=max(rpm,a[i].len);
    sort(a,a+n,cmp);
    while(m--){
        cin>>x>>y;
        if(x.size()!=y.size()){
            cout<<0<<'\n';
            continue;
        }
        int st=-1,ed,dl;
        for(int i=0;i<x.size();i++)
            if(x[i]!=y[i])
                st=(st==-1?i:st),ed=i;
        dl=ed-st+1;
        if(dl>rpm){
            cout<<0<<'\n';
            continue;
        }
        int cnt=0;
        for(int i=n-1;a[i].len>=dl;i--){
            if(a[i].len>x.size())continue;
            for(int j=(st-a[i].len+dl<0?0:st-a[i].len+dl);j+a[i].len<=x.size()&&j<=st;j++){
                if(x.substr(j,a[i].len)==a[i].s1&&y.substr(j,a[i].len)==a[i].s2)
                    cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}