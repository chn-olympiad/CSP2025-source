#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
    string s1,s2;
    int lenn,f,e;
}s[N];
string a,b;
int n,q,maxn,minn,cnt;
bool bijiao(int st,int ed,int num){
    if(st<0||ed>=a.size()) return false;
    for(int i=st;i<=ed;i++){
        if(!(a[i]==s[num].s1[i-st]&&b[i]==s[num].s2[i-st])) return false;
    }
    return true;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i].s1>>s[i].s2;
        maxn=-1,minn=INT_MAX;
        for(int j=0;j<s[i].s1.size();j++){
            if(s[i].s1[j]!=s[i].s2[j]) {
                minn=min(minn,j);
                maxn=max(maxn,j);
            }
        }
        s[i].f=minn;
        s[i].e=maxn;
        s[i].lenn=maxn-minn+1;
        //cout<<s[i].f<<' '<<s[i].e<<' '<<s[i].lenn<<endl;
    }
    while(q--){
        cnt=0;
        cin>>a>>b;
        if(a.size()!=b.size()){
            cout<<0<<endl;
            continue;
        }
        maxn=-1,minn=INT_MAX;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) {
                minn=min(minn,i);
                maxn=max(maxn,i);
            }
        }
        for(int i=1;i<=n;i++){
            if(s[i].lenn!=maxn-minn+1) break;
            bool flag=bijiao(minn-(s[i].f),maxn+(s[i].lenn-s[i].e-1),i);
            if(flag) {
                cnt++;
                //cout<<i<<endl;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}