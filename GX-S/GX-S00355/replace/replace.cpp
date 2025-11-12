#include<bits/stdc++.h>
using namespace std;
struct str{
    string sf,ss;
    int len,b,bn;
}s[200010];
long long n,q,l,r,st[5000010],bf,bs,sum;
bool app[200];
string tf,ts;
int cmp(str a,str b){
    return a.len<b.len;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i].sf>>s[i].ss;
        s[i].len=s[i].sf.size();
        for(int j=0;j<s[i].sf.size();j++){
            if(s[i].sf[j]=='b'){
                s[i].b=j;
            }
            if(s[i].ss[j]=='b'){
                s[i].bn=j;
            }
        }
    }
    sort(s+1,s+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(st[s[i].len]==0) st[s[i].len]=i;
    }
    for(int i=1;i<=q;i++){
        sum=0;
        memset(app,0,sizeof(app));
        cin>>tf>>ts;
        if(tf.size()!=ts.size()){
            cout<<0<<'\n';
        }
        else{
            l=0;
            r=tf.size()-1;
            for(int j=0;j<tf.size();j++){
                if(tf[j]=='b') bf=j;
                if(ts[j]=='b') bs=j;
            }
            for(int j=n;j>=1;j--){
                if(s[j].len>tf.size()){
                    continue;
                }
                if(s[j].len-s[j].b<=tf.size()-bf&&s[j].b<=bf&&s[j].len-s[j].bn<=ts.size()-bs&&s[j].bn<=bs&&s[j].bn-s[j].b==bs-bf){
                    sum++;
                }
            }
            cout<<sum<<'\n';
        }
    }
    return 0;
}
