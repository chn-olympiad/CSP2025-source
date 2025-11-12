#include <bits/stdc++.h>
using namespace std;
struct BIT{
    int c[5000005],n;
    inline void init(int nn){
        n=nn;
        for(int i=0;i<=n;i++){
            c[i]=0;
        }
    }
    inline void modify(int x,int op){
        for(;x<=n;x+=(x&(-x))){
            c[x]+=op;
        }
    }
    inline int query(int x){
        int res=0;
        for(;x;x-=(x&(-x))){
            res+=c[x];
        }
        return res;
    }
}bb;
struct node{
    int s[27];
}d1[5000005],d2[5000005];
const int base=29;
const long long P1=23234878517959LL,P2=42787584738859LL;
char stra[5000005],strb[5000005];
string s[200005],t[200005],a[200005],b[200005];
int ans[200005],T1,T2,pa[200005],pb[200005],l1[5000005],r1[5000005],l2[5000005],r2[5000005],tot1,tot2;
map<pair<long long,long long>,vector<int>> m;
vector<array<int,4>> qst;
inline void dfs1(int x){
    l1[x]=r1[x]=++tot1;
    for(int i=1;i<=26;i++){
        if(d1[x].s[i]){
            dfs1(d1[x].s[i]);
            r1[x]=r1[d1[x].s[i]];
        }
    }
}
inline void dfs2(int x){
    l2[x]=r2[x]=++tot2;
    for(int i=1;i<=26;i++){
        if(d2[x].s[i]){
            dfs2(d2[x].s[i]);
            r2[x]=r2[d2[x].s[i]];
        }
    }
}
inline void add_quest(int l1,int r1,int l2,int r2){
    qst.push_back({-r1,-r2,0,1});
    qst.push_back({-(l1-1),-r2,0,-1});
    qst.push_back({-r1,-(l2-1),0,-1});
    qst.push_back({-(l1-1),-(l2-1),0,1});
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        scanf("%s%s",stra+1,strb+1);
        int len=strlen(stra+1);
        int x=0,y=len+1;
        while(x<len&&stra[x+1]==strb[x+1]){
            x++;
        }
        while(y>1&&stra[y-1]==strb[y-1]){
            y--;
        }
        if(x==len){
            continue;
        }
        long long now1=0,now2=0;
        for(int j=x+1;j<y;j++){
            now1=(now1*base+stra[j]-96)%P1;
            now2=(now2*base+stra[j]-96)%P2;
        }
        for(int j=x+1;j<y;j++){
            now1=(now1*base+strb[j]-96)%P1;
            now2=(now2*base+strb[j]-96)%P2;
        }
        m[{now1,now2}].push_back(i);
        for(int j=x;j>=1;j--){
            s[i]+=stra[j];
        }
        for(int j=y;j<=len;j++){
            t[i]+=stra[j];
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%s%s",stra+1,strb+1);
        int len=strlen(stra+1),lenb=strlen(strb+1);
        if(len!=lenb) continue;
        int x=0,y=len+1;
        while(x<len&&stra[x+1]==strb[x+1]){
            x++;
        }
        while(y>1&&stra[y-1]==strb[y-1]){
            y--;
        }
        long long now1=0,now2=0;
        for(int j=x+1;j<y;j++){
            now1=(now1*base+stra[j]-96)%P1;
            now2=(now2*base+stra[j]-96)%P2;
        }
        for(int j=x+1;j<y;j++){
            now1=(now1*base+strb[j]-96)%P1;
            now2=(now2*base+strb[j]-96)%P2;
        }
        m[{now1,now2}].push_back(-i);
        for(int j=x;j>=1;j--){
            a[i]+=stra[j];
        }
        for(int j=y;j<=len;j++){
            b[i]+=stra[j];
        }
    }
    for(auto [i,quests]:m){
        qst.clear();
        T1=T2=1;
        for(int i=1;i<=26;i++){
            d1[1].s[i]=d2[1].s[i]=0;
        }
        for(auto j:quests){
            if(j<0){
                j=-j;
                int len=a[j].length(),p=1;
                for(int k=0;k<len;k++){
                    if(!d1[p].s[a[j][k]-96]){
                        d1[p].s[a[j][k]-96]=++T1;
                        for(int i=1;i<=26;i++){
                            d1[T1].s[i]=0;
                        }
                    }
                    p=d1[p].s[a[j][k]-96];
                }
                pa[j]=p;
                len=b[j].length(),p=1;
                for(int k=0;k<len;k++){
                    if(!d2[p].s[b[j][k]-96]){
                        d2[p].s[b[j][k]-96]=++T2;
                        for(int i=1;i<=26;i++){
                            d2[T2].s[i]=0;
                        }
                    }
                    p=d2[p].s[b[j][k]-96];
                }
                pb[j]=p;
            }
        }
        tot1=tot2=0;
        dfs1(1);
        dfs2(1);
        for(auto j:quests){
            if(j>0){
                int p1=1,p2=1;
                int len=s[j].length();
                for(int k=0;k<len;k++){
                    if(!d1[p1].s[s[j][k]-96]){
                        p1=0;
                        break;
                    }
                    p1=d1[p1].s[s[j][k]-96];
                }
                len=t[j].length();
                for(int k=0;k<len;k++){
                    if(!d2[p2].s[t[j][k]-96]){
                        p2=0;
                        break;
                    }
                    p2=d2[p2].s[t[j][k]-96];
                }
                if(p1&&p2){
                    add_quest(l1[p1],r1[p1],l2[p2],r2[p2]);
                }
            } else{
                qst.push_back({-l1[pa[-j]],-l2[pb[-j]],-j,0});
            }
        }
        bb.init(T2);
        sort(qst.begin(),qst.end());
        for(auto [x,y,p,op]:qst){
            y=-y;
            if(!p){
                if(y)
                    bb.modify(y,op);
            } else{
                ans[p]=bb.query(T2)-bb.query(y-1);
            }
        }
    }
    for(int i=1;i<=q;i++){
        printf("%d\n",ans[i]);
    }

    return 0;
}
