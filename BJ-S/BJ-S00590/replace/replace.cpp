#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10,M=5e6+10,mod=1e7+7;
int n,m;
char s1[M],s2[M];
struct node{
    int l1,r1,l2,r2,t;
}a[N];
multiset<pair<int,int> > st;
map<pair<int,int>,int> mp;
void do1(){
    for(int t=1;t<=m;t++){
        scanf("%s%s",s1+1,s2+1);
        if(strlen(s1+1)!=strlen(s2+1)){
            puts("0");
            continue;
        }
        int len=strlen(s1+1);
        int f1=0,f2=0,l1=0,l2=0,r1=0,r2=0;
        for(int j=1;j<=len;j++){
            if(s1[j]=='b') f1=j;
            if(s2[j]=='b') f2=j;
            if(s1[j]=='a'){
                if(!f1) l1++;
                else r1++;
            }
            if(s2[j]=='a'){
                if(!f2) l2++;
                else r2++;
            }
        }
        int ans=0,tt=f1-f2;
        for(int i=1;i<=n;i++){
            if(a[i].t==tt && a[i].l1<=l1 && a[i].r1<=r1 && a[i].l2<=l2 && a[i].r2<=r2){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    exit(0);
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&m);
    bool flag=1;
    for(int i=1;i<=n;i++){
        scanf("%s%s",s1+1,s2+1);
        int len=strlen(s1+1);
        int h1=0,h2=0;
        int cnta=0,cntb=0;
        for(int j=1;j<=len;j++){
            if(s1[j]=='a') cnta++;
            if(s1[j]=='b') cntb++;
            h1=h1*30+s1[j]-'a'+1,h1%=mod;
            h2=h2*30+s2[j]-'a'+1,h2%=mod;
        }
        st.insert(make_pair(h1,h2));
        if(cnta+cntb!=len || cntb!=1) flag=0;
        cnta=cntb=0;
        for(int j=1;j<=len;j++){
            if(s2[j]=='a') cnta++;
            if(s2[j]=='b') cntb++;
        }
        if(cnta+cntb!=len || cntb!=1) flag=0;
        int f1=0,f2=0;
        for(int j=1;j<=len;j++){
            if(s1[j]=='b') f1=j;
            if(s2[j]=='b') f2=j;
            if(s1[j]=='a'){
                if(!f1) a[i].l1++;
                else a[i].r1++;
            }
            if(s2[j]=='a'){
                if(!f2) a[i].l2++;
                else a[i].r2++;
            }
        }
        a[i].t=f1-f2;
    }
    if(flag) do1();
    for(int i=1;i<=m;i++){
        scanf("%s%s",s1+1,s2+1);
        if(strlen(s1+1)!=strlen(s2+1)){
            puts("0");
            continue;
        }
        int len=strlen(s1+1),ans=0;
        int lt=1,rt=strlen(s1+1);
        while(lt<=len && s1[lt]==s2[lt]) lt++;
        while(rt>=1 && s1[rt]==s2[rt]) rt--;
        for(int l=1;l<=len;l++){
            int h1=0,h2=0;
            for(int r=l;r<=len;r++){
                h1=h1*30+s1[r]-'a'+1,h1%=mod;
                h2=h2*30+s2[r]-'a'+1,h2%=mod;
                if(l>lt || r<rt) continue;
                if(st.count(make_pair(h1,h2))){
                    ans+=st.count(make_pair(h1,h2));
                }

            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
