#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q,ans,b[maxn][2],num[maxn],sum[maxn][2];
string s1[maxn],s2[maxn];
map<string,vector<string> > mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        int tmp=s1[i].size();
        for(int j=0;j<tmp;j++){
            if(s1[i][j]=='b') b[i][0]=j;
            if(s2[i][j]=='b') b[i][1]=j;
        }
        int kk=b[i][0]-b[i][1];
        if(kk<0) sum[-kk][0]++;
        else sum[kk][1]++;
    }
    if(n<=100){
        while(q--){
            string s,t;cin>>s>>t;
            int n=s.size();ans=0;
            for(int i=1;i<=n;i++) mp[s1[i]].push_back(s2[i]);
            for(int i=0;i<n;i++){
                string tmp1="",tmp2="",tmp3="",tmp4="";
                for(int j=i+1;j<n;j++) tmp3+=s[j],tmp4+=t[j];
                if(tmp3!=tmp4) continue;
                for(int j=i;j>=0;j--){
                    tmp1=s[j]+tmp1,tmp2=t[j]+tmp2;
                    bool flag=0;
                    for(int k=0;k<j;k++) if(s[k]!=t[k]){flag=1;break;}
                    if(flag==1) continue;
                    for(string k:mp[tmp1]){
                        if(k==tmp2) ans++;
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }else{
        while(q--){
            ans=0;
            string s,t,l="",r="";
            cin>>s>>t;
            int k1,k2,n=s.size();
            for(int i=0;i<n;i++){
                if(s[i]=='b') k1=i;
                if(t[i]=='b') k2=i;
            }
            int tmp=k1-k2;
            if(tmp<0) ans=sum[-tmp][0];
            else ans=sum[tmp][1];
            cout<<ans<<"\n";
        }
    }
    return 0;
}
/*
4 2
xabcx xadex
ad cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/