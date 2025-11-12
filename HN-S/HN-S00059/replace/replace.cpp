#include <bits/stdc++.h>
using namespace std;
#define int long long
namespace fisher{
const int N=2e5+5;
int n,q;
string x,y,s[N][2];
int getp(string &s,string &t){
    int l1=s.size(),l2=t.size();
    for(int i=0;i<l1;i++){
        for(int j=i,k=0;j<l1&&k<l2;j++,k++){
            if(s[j]!=t[k]) break;
            if(k==l2-1) return i;
        }
    }
    return -1;
}
bool check(int i,int p){
    int len=s[i][0].size();
    string lx=x;
    for(int j=p,k=0;k<len;j++,k++)
        lx[j]=s[i][1][k];
    return lx==y;
}
int solve(){
    int res=0,p1,p2;
    for(int i=1;i<=n;i++){
        p1=getp(x,s[i][0]);
        if(p1==-1) continue;
        p2=getp(y,s[i][1]);
        if(p2==-1||p1!=p2) continue;
        res+=check(i,p1);
    }
    return res;
}
signed ckt(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s[i][0]>>s[i][1];
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<solve()<<'\n';
    }
    return 0;
}}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    return fisher::ckt();
}