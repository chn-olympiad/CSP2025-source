#include<bits/stdc++.h>
using namespace std;
struct Pair{
    string s1,s2;
}S[1001001],T;
int n,m,ans;
int judge(string s,string t,string t1,string t2){
    int tot=0,cnt=0;
    string s1=s;
    while(tot<s.size()){
        s1=s;
        if(s1.substr(tot,t1.size())==t1)
            s1.replace(tot,t1.size(),t2);
        if(s1==t) cnt++;
        tot++;
    }
    return cnt;
}
void solve(string s,string t){
    for(int i=1;i<=n;i++)
        ans+=judge(s,t,S[i].s1,S[i].s2);
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>S[i].s1>>S[i].s2;
    while(m--){
        ans=0;
        cin>>T.s1>>T.s2;
        solve(T.s1,T.s2);
        cout<<ans<<endl;
    }
	return 0;
}
