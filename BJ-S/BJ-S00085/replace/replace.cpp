#include<bits/stdc++.h>
using namespace std;

const int maxn=3e5+5;
int n,q;
string s1[maxn],s2[maxn],t1,t2;
long long ans=0;

map<pair<string,string>,int> mp;

vector<pair<int,int> > pp[maxn];

bool judge(string s){
    bool flag=0,flag2=0;
    int n=s.size();s=" "+s;
    for(int i=1;i<=n;i++){
        if(s[i]>='c'){
            flag=0;
            break;
        }
        if(s[i]=='b'){
            if(flag2==1) flag2=0;
            else{
                flag=0;break;
            }
        }
    }
    return flag;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i],mp[make_pair(s1[i],s2[i])]=1;
    bool flag=1;
    for(int i=1;i<=n;i++) flag&=judge(s1[i]),flag&=judge(s2[i]);

    if(flag==1){
        for(int i=1;i<=n;i++){
            int m=s1[i].size(),l=0,r=m-1;
            for(int j=0;j<=m-1;j++){
                if(s1[i][j]=='b'){
                    l=i;break;
                }
            }
            for(int j=0;j<=m-1;j++){
                if(s2[i][j]=='b'){
                    r=i;break;
                }
            }
            pp[r-l+n].push_back({min(l,r),m-max(l,r)});
        }
    }
    while(q--){
        cin>>t1>>t2;ans=0;
        int m=t1.size(),l=1,r=n;

        if(flag==1 && m>=1000){
            l=0,r=n-1;
            for(int i=0;i<=m-1;i++){
                if(t1[i]=='b'){
                    l=i;break;
                }
            }
            for(int i=0;i<=m-1;i++){
                if(t2[i]=='b'){
                    r=i;break;
                }
            }
            for(int i=0;i<pp[r-l+n].size();i++){
                if(pp[r-l+n][i].first<=min(l,r) && m-max(l,r)<=pp[r-l+n][i].second) ans++;
            }
            printf("%lld\n",ans);
        }
        else{
            t1=" "+t1,t2=" "+t2;
            for(int i=1;i<=m;i++){
                if(t1[i]!=t2[i]){
                    l=i;break;
                }
            }
            for(int i=m;i>=1;i--){
                if(t1[i]!=t2[i]){
                    r=i;break;
                }
            }
            for(int i=1;i<=l;i++){
                string q1="",q2="";
                if(l<r) q1=t1.substr(i,r-i),q2=t2.substr(i,r-i);
                for(int j=r;j<=m;j++){
                    q1+=t1[j],q2+=t2[j];
                    for(int k=1;k<=n;k++) if(s1[k]==q1 && s2[k]==q2) ans++;
                }
            }
            printf("%lld\n",ans);
        }

    }
    return 0;
}
