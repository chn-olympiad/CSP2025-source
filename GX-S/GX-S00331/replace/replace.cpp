#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#define MXN 5000010
#define fs first
#define sc second
#define ll long long
using namespace std;
int n,qs,inf=1e9;
typedef pair<int,int>g;
g gs[MXN];
string s1[200010],s2[200010],t1,t2;
int lb(int x){
    return x&-x;
}
struct TRE{
    ll s[200010],r;
    void ad(int p,ll x){
        while(p<=r){s[p]+=x;p+=lb(p);}
        return;
    }
    ll qy(int p){
        ll res=0;
        while(p){res+=s[p];p-=lb(p);}
        return res;
    }
}tr;
struct Q{
    int ml,mr,p,ans;
}qt[MXN];
bool cmpl(Q a,Q b){
    return a.ml<b.ml;
}
bool cmpp(Q a,Q b){
    return a.p<b.p;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>qs;
    int cr=0,mx=0;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        mx=max(mx,(int)s1[i].length());
        mx=max(mx,(int)s2[i].length());
        int ca=0,cb=0;
        for(int j=0;j<s1[i].size();j++){
            ca+=(s1[i][j]=='a');
            cb+=(s1[i][j]=='b');
        }
        cr+=(ca==s1[i].size()-1&&cb==1);
    }
    if(cr==n){
        for(int i=1;i<=n;i++){
            for(int j=0;j<s1[i].size();j++){
                if(s1[i][j]=='b'){gs[i].fs=j;gs[i].sc=s1[i].size()-j-1;break;}
            }
            for(int j=0;j<s2[i].size();j++){
                if(s2[i][j]=='b'){gs[i].fs=max(gs[i].fs,(int)j);gs[i] .sc=max(gs[i].sc,(int)s2[i].size()-j-1);break;}
            }
            cout<<gs[i].fs<<" "<<gs[i].sc<<endl;
        }
        sort(gs+1,gs+1+n);

        for(int i=1;i<=qs;i++){

            cin>>t1>>t2;
            qt[i].p=i;
            if(t1!=t2){
                qt[i].ml=inf;
                qt[i].ans=0;
                continue;
            }
            for(int i=0;i<t1.size();i++){
                if(t1[i]=='b'){
                    qt[i].ml=i;
                    qt[i].mr=t1.size()-i-1;
                    break;
                }
            }
        }
        //cout<<"ww"<<endl;
        sort(qt+1,qt+1+qs,cmpl);
        int j=0;
//cout<<"ww"<<endl;
        tr.r=mx+2;
        for(int i=1;i<=qs;i++){
            cout<<qt[i].ml<<endl;
            while(j+1<=n&&gs[j+1].fs<=qt[i].ml){
                //cout<<j<<endl;
                j++;
                tr.ad(gs[j].sc+1,1);
            }
            cout<<endl;
            qt[i].ans=tr.qy(qt[i].mr+1);
        }
        sort(qt+1,qt+1+qs,cmpp);
        for(int i=1;i<=qs;i++)cout<<qt[i].ans<<endl;
    }

    return 0;
}
