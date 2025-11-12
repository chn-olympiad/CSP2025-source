#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
string t1[200005],t2[200005];
int n,p;

int fd(string sa,string sb){
    int lenth=0;
    for(int i=0;i<sa.size()-sb.size();i++){
        for(int j=i;j<sb.size();j++){
            if(sa[j]==sb[j]) lenth++;
        }
        if(lenth==sb.size()) return i;
    }
    return -1;
}

string getstr(string ss,int st,int ed){
    string t;
    for(int i=st;i<ed;i++){
        t+=ss[i];
    }
    return t;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>p;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    for(int i=1;i<=p;i++) cin>>t1[i]>>t2[i];
    for(int i=1;i<=p;i++){
        int ans=0;
        for(int j=1;j<=n;j++){
            if(fd(t1[i],s1[j])!=-1){
                if( (getstr(t1[i],0,fd( t1[i],s1[j]) ) + s2[j]+ getstr(t1[i],fd( t1[i],s1[j]),t1[i].size()-1))==s2[i] ) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
