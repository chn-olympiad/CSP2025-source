#include<bits/stdc++.h>
using namespace std;
#define long long ll
struct sp{
    string a,b;
    int xx;
}Sp[200005];
int n,q;
int aa[200005];
int check(string s,string ss){
    int xposs=-1,yposs=-1;
    for(int i=0;i<s.size();i++){
        if((s[i]!='a'&&s[i]!='b')||(ss[i]!='a'&&ss[i]!='b')) return -1;
        if(s[i]=='b') xposs=i;
        if(ss[i]=='b') yposs=i;
    } 
    aa[abs(xposs-yposs)]++;
    return abs(xposs-yposs);
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    int A=1;
    for(int i=1;i<=n;i++){
        cin>>Sp[i].a>>Sp[i].b;
        if(A==0||check(Sp[i].a,Sp[i].b)==-1) A=0;
    } 
    if(A){
        for(int i=1;i<=q;i++){
            string x,y;
            cin>>x>>y;
            if(x.size()!=y.size()) printf("0\n");
            int q=x.find('b');
            int w=y.find('b');
            int af=abs(q-w);
            printf("%d\n",aa[af]); 
        }
    }
    for(int i=1;i<=q;i++){
        string x,y;
        cin>>x>>y;
        int ans=0;
        if(x.size()!=y.size()) printf("0\n");
        for(int i=1;i<=n;i++){
            if(Sp[i].a.size()>x.size()) continue;
            if(Sp[i].a.size()==x.size()){
                if(Sp[i].a==x) {ans++;continue;}
                else continue;
            }
            int gg=x.find(Sp[i].a),hh=y.find(Sp[i].b);
            if(gg==-1||hh==-1) continue;
            while(gg!=hh&&gg!=-1&&hh!=-1){
                gg=x.find(Sp[i].a,gg),hh=y.find(Sp[i].b,hh);
            }
            if(gg==hh&&gg!=-1&&x.replace(gg,Sp[i].a.size(),Sp[i].b)==y) ans++;
        }
        printf("%d\n",ans);
    } 
    return 0;
}