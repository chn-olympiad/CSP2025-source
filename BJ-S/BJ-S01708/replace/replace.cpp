#include<bits/stdc++.h>
#define _for(i,x,y) for(int i=x;i<=y;++i)
#define _rep(i,x,y) for(int i=x;i<y;++i)
#define _forp(i,x,y,z) for(int i=x;i<=y;i+=z)
using namespace std;
#define ull unsigned long long
const int N=5000006,base=13331;
ull hsh1[N],hsh2[N],pw[N];
struct info{
    ull  h1,h2,sz;
}S[N];
map<pair<ull,ull>,bool> mp;
int n,q;

bool cmp(info x,info y){
    return x.sz<y.sz;
}

ull gethash(int l,int r,int op){
    if(l>r) return 0;
    if(op==0){
        return hsh1[r]-hsh1[l-1]*pw[r-l+1];
    }else return hsh2[r]-hsh2[l-1]*pw[r-l+1];
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    pw[0]=1;
    _for(i,1,N-6) pw[i]=pw[i-1]*base;
    _for(i,1,n){
        string a,b;
        cin>>a>>b;
        ull sz=(int)a.size();
        ull h1=0,h2=0;
        _rep(i,0,sz){
            h1=h1*base+a[i];
        }
        _rep(i,0,sz){
            h2=h2*base+b[i];
        }
        //cout<<h1<<' '<<h2<<'\n';
        mp[{h1,h2}]=1;
        S[i]={h1,h2,sz};
    }
    sort(S+1,S+n+1,cmp);
    while(q--){
        int m;
        string t1,t2;
        cin>>t1>>t2;
        m=t1.size();
        t1=" "+t1;
        t2=" "+t2;

        _for(i,1,m){
            hsh1[i]=hsh1[i-1]*base+t1[i];
        }
        _for(i,1,m){
            hsh2[i]=hsh2[i-1]*base+t2[i];
        }

        int zzz=m+1;
        for(int i=m;i;--i){
            if(t1[i]==t2[i]) zzz=i;
            else break;
        }
        int cnt=0;
        _for(i,1,m){
            int ll=0,L=1,R=n;
            while(L<=R){
                int mid=L+R>>1;
                if(S[mid].sz+i>=zzz) ll=mid,R=mid-1;
                else L=mid+1;
            }
            //cout<<ll<<' ';
            _for(j,ll,n){
                if(S[j].sz+i-1>m) break;
                int ll=i-1;
                if(gethash(1,ll,0)!=gethash(1,ll,1)) break;
                //[1,ll]
                int rr=S[j].sz+i;
                //[rr,n]
                if(gethash(1,ll,0)==gethash(1,ll,1) &&
                   gethash(rr,m,0)==gethash(rr,m,1) &&
                   gethash(ll+1,rr-1,0)==S[j].h1    &&
                   gethash(ll+1,rr-1,1)==S[j].h2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
