#include<bits/stdc++.h>
using namespace std;
const int N=200010,base1=107,base2=998244353;
long long h1[N*30],h2[N*30],pw[N*30];
string s[N][2],t[N][2];
struct node{
    int del,pre,suf;
};
node a[N];
bool operator <(node a1,node a2){
    if(a1.del==a2.del) return a1.pre<a2.pre;
    else return a1.del<a2.del;
}
bool check(string s1){
    int cnt1=0,cnt2=0;
    for(int i=0;i<s1.size();i++)
        if(s1[i]=='a') cnt1++;
        else if(s1[i]=='b') cnt2++;
    return cnt1+cnt2==s1.size()&&cnt2==1;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    pw[0]=1;
    for(int i=1;i<=5e6;i++) pw[i]=(pw[i-1]*base1)%base2;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        //B&=check(s[i][0]),B&=check(s[i][1]);
    }
    for(int i=1;i<=q;i++){
        cin>>t[i][0]>>t[i][1];
        //B&=check(t[i][0]),B&=check(t[i][1]);
    }
    int ans=0;
    for(int i=1;i<=q;i++){
        ans=0;
        if(t[i][0].size()!=t[i][1].size()){
            cout<<0<<'\n';
            continue;
        }
        h1[0]=t[i][0][0];
        for(int j=1;j<t[i][0].size();j++){
            h1[j]=(1ll*h1[j-1]*base1+t[i][0][j])%base2;
        }
        h2[0]=t[i][1][0];
        for(int j=1;j<t[i][1].size();j++){
            h2[j]=(1ll*h2[j-1]*base1+t[i][1][j])%base2;
        }
        int l=1e9,r=0;
        for(int j=0;j<t[i][0].size();j++){
            if(t[i][0][j]!=t[i][1][j]) l=min(l,j),r=max(r,j);
        }
        //cout<<l<<" "<<r<<'\n';
        for(int j=1;j<=n;j++){
            if(s[j][0].size()>t[i][0].size()||s[j][0].size()<r-l+1) continue;
            int hh1=s[j][0][0];
            for(int k=1;k<s[j][0].size();k++){
                hh1=(1ll*hh1*base1+s[j][0][k])%base2;
            }
            int hh2=s[j][1][0];
            for(int k=1;k<s[j][1].size();k++){
                hh2=(1ll*hh2*base1+s[j][1][k])%base2;
            } 
            for(int k=0;k<t[i][0].size();k++){
                int ll=k,rr=k+s[j][0].size()-1;
                if(ll>l||rr<r||rr>=t[i][0].size()) continue;
                //cout<<k<<" ";
                int now;
                if(k==0) now=h1[rr];
                else now=(h1[rr]-h1[ll-1]*pw[rr-ll+1]%base2+base2)%base2;
                if(now==hh1){
                    int res;
                    if(k==0) res=h2[rr];
                    else res=(h2[rr]-h2[ll-1]*pw[rr-ll+1]%base2+base2)%base2;
                    if(res==hh2) ans++;
                }
            }
            //cout<<'\n';
        }
        cout<<ans<<'\n';
    }
    /*if(B){
        for(int i=1;i<=n;i++){
            int pos1,pos2;
            for(int j=0;j<s[i][0].size();j++)
                if(s[i][0][j]=='b') pos1=j;
            for(int j=0;j<s[i][1].size();j++)
                if(s[i][1][j]=='b') pos2=j;
            int delta=pos2-pos1,pree=pos1;
            a[i]={delta,pree,s[i][0].size()-pos1};
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=q;i++){
            if(t[i][0].size()!=t[i][1].size()){
                cout<<0<<'\n';
                continue;
            }
            int pos1,pos2;
            for(int j=0;j<t[i][0].size();j++)
                if(t[i][0][j]=='b') pos1=j;
            for(int j=0;j<t[i][1].size();j++)
                if(t[i][1][j]=='b') pos2=j;
            //cout<<pos1<<" "<<pos2<<'\n';
            int delta=pos2-pos1,pree=pos1;
            //cout<<delta<<" "<<pree<<'\n';
            int r=upper_bound(a+1,a+n+1,(node){delta,pree,t[i][0]-})-a;
            int l=upper_bound(a+1,a+n+1,(node){delta-1,10000000})-a;
            //cout<<a[r-1].del<<" "<<a[r-1].pre<<'\n';
            //cout<<a[l].del<<" "<<a[l].pre<<'\n';
            for(int l=)
            //cout<<r-l<<'\n';
        }
    }*/
}