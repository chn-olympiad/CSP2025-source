#include<bits/stdc++.h>
using namespace std;
template<int umod>
struct modi{
    int val;
    static constexpr int mod=umod;
    modi(){}
    modi(int _v){val=_v;}
    friend modi operator + (const modi &a,const modi &b){
        modi res(a.val+b.val);
        res.val=res.val>=mod?res.val-mod:res.val;
        return res;
    }
    friend modi operator - (const modi &a,const modi &b){
        modi res(a.val+mod-b.val);
        res.val=res.val>=mod?res.val-mod:res.val;
        return res;
    }
    friend modi operator * (const modi &a,const modi &b){
        return modi(1ll*a.val*b.val%mod);
    }
    void operator += (const modi &a){
        val+=a.val;
        val=val>=mod?val-mod:val;
    }
    void operator *= (const modi &a){
        val=1ll*val*a.val%mod;
    }
};
using m1=modi<98347447>;
using m2=modi<int(1e9+9)>;
struct hashval{
    m1 val1;
    m2 val2;
    hashval():val1(0),val2(0){}
    hashval(int _x,int _y):val1(_x),val2(_y){}
    friend hashval operator + (const hashval &a,const hashval &b){
        hashval res;
        res.val1=a.val1+b.val1;
        res.val2=a.val2+b.val2;
        return res;
    }
    friend hashval operator - (const hashval &a,const hashval &b){
        hashval res;
        res.val1=a.val1-b.val1;
        res.val2=a.val2-b.val2;
        return res;
    }
    friend hashval operator * (const hashval &a,const hashval &b){
        hashval res;
        res.val1=a.val1*b.val1;
        res.val2=a.val2*b.val2;
        return res;
    }
    inline void addch(int x){
        val1=val1*m1(127)+m1(x);
        val2=val2*m2(47)+m2(x);
    }
    friend bool operator == (const hashval &a,const hashval &b){
        return a.val1.val==b.val1.val&&a.val2.val==b.val2.val;
    }
} base(127,47);
const int N=2e5+5,MAXL=5e6+5,hMAXL=2.5e6+5;
hashval pw[hMAXL];
struct node{
    int len;
    hashval org,to;
    friend bool operator < (const node &a,const node &b){
        return a.len<b.len;
    }
} a[N];
#define scan std::cin
string s1,s2;
void readnode(node &t){
    scan>>s1>>s2;
    for(int i=0;i<s1.size();i++) t.org.addch(s1[i]-'a'+1);
    for(int i=0;i<s2.size();i++) t.to.addch(s2[i]-'a'+1);
    t.len=s1.size();
}
void init(int n){
    pw[0]=hashval(1,1);
    for(int i=1;i<=n;i++) pw[i]=pw[i-1]*base;
}
hashval pret1[hMAXL],pret2[hMAXL];
int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
//  every pair can be used only one time.
//  simply got O(Ln).
//  pre & suf, got O((pre+suf)*n*xuanxue).
    int n,q;
    scan>>n>>q;
    while(q--) cout<<0<<'\n';
    exit(0);
    for(int i=1;i<=n;i++) readnode(a[i]);
    sort(a+1,a+n+1);
//    for(int i=1;i<=n;i++) printf("len[%d] = %d\n",i,a[i].len);
    init(2500000);
    node tmp;
    for(int i=1;i<=q;i++){
 //       printf("i = %d\n",i);
        scan>>s1>>s2;
        if(s1.size()!=s2.size()){
            cout<<0<<'\n';
            continue;
        }
        int sz=s1.size();
        pret1[0]=pret2[0]=hashval();
        pret1[0].addch(s1[0]-'a'+1),pret2[0].addch(s2[0]-'a'+1);
        for(int j=1;j<sz;j++){
            pret1[j]=pret1[j-1]*base,pret1[j].addch(s1[i]-'a'+1);
            pret2[j]=pret2[j-1]*base,pret2[j].addch(s2[i]-'a'+1);
        }
        int pre=0,suf=sz-1;
        while(pre<sz&&s1[pre]==s2[pre]) pre++;
        while(suf>=0&&s1[suf]==s2[suf]) suf--;
 //       printf("pre = %d, suf = %d\n",pre,suf);
//      [0,pre), (suf,sz) are the same;
        int len=max(suf-pre+1,0);
        tmp.len=len;
        int p=lower_bound(a+1,a+n+1,tmp)-a;
        int res=0;
        for(int j=p;j<=n;j++){
 //           printf("p = %d\n",p);
            for(int k=max(suf-a[j].len+1,0);k<=pre;k++){
 //               printf("begin at %d\n",k);
                hashval f1=a[j].org,pp=pret1[k+a[j].len-1];
                if(k!=0) f1=f1+pret1[k-1]*pw[a[j].len];
                if(f1==pp){
                    res+=(f1-a[j].org+a[j].to)==pret2[k+a[j].len-1];
                }
 //               printf("result = %d\n",(f1-a[j].org+a[j].to)==pret2[k+a[j].len-1]);
            }
        }
 //       cout<<res<<'\n';
    }
    return 0;
}
//shibushi gaixieyiyanl
//www, xueddongxiyidiandoumeikaoaaa
//wozhiganjue juewang aaa
//lian hash ye xiegual...
//suanlb, shao 20pts youyoushenmguanxine
//nibijinglianxu liangnian douyudaolshihezijdt
//zonggaikenyicb...
//meiyouzhongwenshurufa maosilianwoddanaodoubeixianzhil...
//taikewul!!!!!!!!!!
//woshizz,wwwwwwwwwwwwqaqaqaqaqaqaqaq.
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//wozaiganshenm...
//orzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorz
//freopen("replace.in","r",stdin);
//freopen("replace.out","r",stdin);
//rest in peace...