#include<bits/stdc++.h>

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)

#define all(vc) vc.begin(),vc.end()
#define SZ(vc) (int)(vc.size())

#define pb push_back
#define fi first
#define se second


using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL,LL> PLL;

const int N=2e5+5,L=5e6+5,P=131,B=200;
int n,q,pl[N],sl[N];
ULL p[L],pre[N],suf[N],mid1[N],mid2[N];
string s[N][2];
vector<ULL>hsh[N][2];
ULL h[L],hh[L];
ULL query(int l,int r){
    if(l>r)return (ULL)0;
    else return h[r]-h[l-1]*p[r-l+1];
}
ULL query2(int l,int r){
    if(l>r)return (ULL)0;
    else return hh[r]-hh[l-1]*p[r-l+1];
}
map<pair<ULL,ULL>,int>mp;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);



    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin>>n>>q;
    p[0]=1;
    rep(i,1,5000000)p[i]=p[i-1]*P;
    rep(i,1,n){
        cin>>s[i][0]>>s[i][1];
        int l=SZ(s[i][0]);
        s[i][0]=' '+s[i][0];
        s[i][1]=' '+s[i][1];
        int left=0,right=l+1;
        rep(j,1,l)if(s[i][0][j]==s[i][1][j])left=j;else break;
        per(j,l,1)if(s[i][0][j]==s[i][1][j])right=j;else break;
        left+=1,right-=1;
        if(left<=right){
            ULL h1,h2;h1=h2=0;
            rep(j,left,right){
                h1=h1*P+s[i][0][j];
                h2=h2*P+s[i][1][j];
            }
            mid1[i]=h1,mid2[i]=h2;
            h1=h2=0;
            rep(j,1,left-1)h1=h1*P+s[i][0][j];
            pl[i]=left-1;pre[i]=h1;
            rep(j,right+1,l)h2=h2*P+s[i][0][j];
            sl[i]=l-right;suf[i]=h2;
            h1=h2=0;
            rep(j,1,l)h1=h1*P+s[i][0][j],h2=h2*P+s[i][1][j];
            mp[{h1,h2}]+=1;
        }
    }

    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        if(SZ(t1)^SZ(t2))cout<<-1<<'\n';
        else{
            int len=SZ(t1);t1=' '+t1,t2=' '+t2;
            int left=0,right=len+1;
            rep(j,1,len)if(t1[j]==t2[j])left=j;else break;
            per(j,len,1)if(t1[j]==t2[j])right=j;else break;
            rep(j,1,len)h[j]=h[j-1]*P+t1[j];
            rep(j,1,len)hh[j]=hh[j-1]*P+t2[j];
            left+=1,right-=1;
            ULL h1,h2;h1=h2=0;
            rep(j,left,right){
                h1=h1*P+t1[j];
                h2=h2*P+t2[j];
            }
            if(len<=B){
                int ans=0;
                rep(i,1,left)rep(j,right,len)ans+=mp[{query(i,j),query2(i,j)}];
                cout<<ans<<'\n';
            }else{
                int ans=0;
                rep(i,1,n){
                    if(mid1[i]==h1&&mid2[i]==h2&&pl[i]<=left-1&&sl[i]<=len-right&&query(left-pl[i],left-1)==pre[i]&&query(right+1,right+sl[i])==suf[i])
                        ++ans;
                }
                cout<<ans<<'\n';
            }
        }
    }




    return 0;
}
