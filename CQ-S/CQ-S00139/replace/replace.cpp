#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define f(i,j,n) for(int i=j;i<=n;i++)
#define F(i,n,j) for(int i=n;i>=j;i--)
#define updmin(a,b) a=min(a,b)
#define updmax(a,b) a=max(a,b)
#define updsum(a,b) a=(a+(b))%mod
#define updtim(a,b) a=a*(b)%mod
using namespace std;
typedef pair<int,int> pii;
namespace fsd{
    const int MX=1<<20;
    char buf[MX],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,MX,stdin),p1==p2)?EOF:*p1++)
    inline int read(){
        int ak=0,csp=1;
        char c=gc();
        while(!isdigit(c)){if(c=='-')csp=-1;c=gc();}
        while(isdigit(c))ak=ak*10+c-'0',c=gc();
        return ak*csp;
    }
    inline string reads(){
        string s;
        char c=gc();
        while(!('a'<=c&&c<='z'))c=gc();
        while('a'<=c&&c<='z')s+=c,c=gc();
        return s;
    }
}
using namespace fsd;
const int N=2e5+10;
const int M=5e6+10;
struct ACt{
    struct abc{
        int mp[29];
        int fail,siz;
    }Tree[M+N*3];
    int root=0,cnt=0;
    void insert(string x){
        int thi=root;
        for(auto v:x){
            if(!Tree[thi].mp[v-'a'])Tree[thi].mp[v-'a']=++cnt;
            thi=Tree[thi].mp[v-'a'];
        }
        Tree[thi].siz++;
    }
    vector<int> h[M];
//    void buildfail(int k,int rf){
////    	cout<<k<<" "<<rf<<endl;
//    	Tree[k].fail=rf;
//        f(j,0,28){
//            if(Tree[k].mp[j]){
////                Tree[Tree[k].mp[j]].fail=rf;
//                buildfail(Tree[k].mp[j],rf);
//            }
//        }
//    }
    void dfs(int k){
        for(auto v:h[k])Tree[v].siz+=Tree[k].siz,dfs(v);
    }
//    string s[M];
//    void dd(int k){
//        f(j,0,28){
//            if(Tree[k].mp[j]){
//            	s[Tree[k].mp[j]]=s[k]+char(j+'a');
//            	dd(Tree[k].mp[j]);
//            }
//        }
//	}
    void build(){
//        buildfail(0,0);
//        dd(0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int k=q.front();q.pop();
            f(j,0,28){
                if(!Tree[k].mp[j]){
                	Tree[k].mp[j]=Tree[Tree[k].fail].mp[j];
				}else{
	                if(Tree[k].fail!=k)Tree[Tree[k].mp[j]].fail=Tree[Tree[k].fail].mp[j];
	                q.push(Tree[k].mp[j]);
				}
            }
        }
        f(i,1,cnt)h[Tree[i].fail].push_back(i);
        dfs(0);
//        f(i,0,cnt){
////            f(j,0,28)if(Tree[i].mp[j]){
////                cout<<i<<"->"<<char(j+'a')<<" "<<Tree[i].mp[j]<<endl;
////            }
//            cout<<i<<" "<<s[i]<<" "<<Tree[i].fail<<" "<<s[Tree[i].fail]<<endl;
//        }
    }
    int ask(string s){
        int thi=0,ans=0;
        for(auto v:s){
//        	cout<<thi<<endl;
            thi=Tree[thi].mp[v-'a'];
            ans+=Tree[thi].siz;
        }
        return ans;
    }
}_trie;
int n,m;
void gs(){
    n=read(),m=read();
    f(i,1,n){
        string s=reads(),t=reads();
        if(s==t)continue;
        int l=0,r=s.size();
        while(s[l]==t[l])l++;
        while(s[r-1]==t[r-1])r--;
        string nw=s.substr(0,l)+char('z'+1)+s.substr(l,r-l)+char('z'+2)+t.substr(l,r-l)+char('z'+3)+t.substr(r);
//        cout<<s<<" "<<t<<" "<<l<<" "<<r<<" "<<nw<<endl;
        _trie.insert(nw);
    }
//    exit(0);
    _trie.build();
    f(i,1,m){
        string s=reads(),t=reads();
        if(s.size()!=t.size()){printf("0\n");continue;}
        int l=0,r=s.size();
        while(s[l]==t[l])l++;
        while(s[r-1]==t[r-1])r--;
//        cout<<l<<" "<<r<<endl;
        string nw=s.substr(0,l)+char('z'+1)+s.substr(l,r-l)+char('z'+2)+t.substr(l,r-l)+char('z'+3)+t.substr(r);
//        cout<<nw<<endl;
        printf("%lld\n",_trie.ask(nw));
    }
}
// #define DXN
signed main(){
//    freopen("replace3.in","r",stdin);
//    freopen("replace.out","w",stdout);
#ifndef DXN
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
#endif
#ifdef NXD
    int t=read();while(t--)
#endif
    gs();
    return 0;
}
