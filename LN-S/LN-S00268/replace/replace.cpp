
#include<bits/stdc++.h>
using namespace std;
const long long b1=101,b2=10007;
const long long p1=1e9+7,p2=998244353;

int n,q;
long long c1[5000010],c2[5000010];
vector<char>s1[200010],s2[200010];
char s[5000010];
map<pair<pair<long long,long long>,pair<long long,long long>>,map<pair<pair<long long,long long>,pair<long long,long long>>,int>>p;
char t1[5000010],t2[5000010];
long long re1[5000010][2],re2[5000010][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    c1[0]=c2[0]=1;
    for(int i=1;i<=5000000;i++){
        c1[i]=c1[i-1]*b1%p1;
        c2[i]=c2[i-1]*b2%p2;
    }
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        int u=strlen(s+1);
        s1[i].push_back('\0');
        for(int j=1;j<=u;j++){
            s1[i].push_back(s[i]);
        }s1[i].push_back('\0');
        scanf("%s",s+1);
        s2[i].push_back('\0');
        for(int j=1;j<=u;j++){
            s2[i].push_back(s[i]);
        }s2[i].push_back('\0');
        int q=0,z=0;
        for(int i=1;i<=u;i++){
            if(s1[i]!=s2[i]){
                if(!q){
                    q=i;
                }z=i;
            }
        }if(q){
            long long r11=0,r12=0,r21=0,r22=0;
            for(int j=q;j<=z;j++){
                r11=(r11+s1[i][j]-'a')*b1%p1;
                r12=(r12+s1[i][j]-'a')*b2%p2;
                r21=(r21+s2[i][j]-'a')*b1%p1;
                r22=(r22+s2[i][j]-'a')*b2%p2;
            }long long q11=0,q12=0;
            long long h11=0,h12=0;
            for(int j=1;j<q;j++){
                q11=(q11+s1[i][j]-'a')*b1%p1;
                q12=(q12+s1[i][j]-'a')*b2%p2;
            }for(int j=z+1;j<=u;j++){
                h11=(h11+s1[i][j]-'a')*b1%p1;
                h12=(h12+s1[i][j]-'a')*b2%p2;
            }p[{{r11,r12},{r21,r22}}][{{q11,q12},{h11,h12}}]++;
        }else{
            long long r1=0,r2=0;
            for(int j=1;j<=u;j++){
                r1=(r1+s1[i][j]-'a')*b1%p1;
                r2=(r2+s1[i][j]-'a')*b2%p2;
            }p[{{0,0},{0,0}}][{{r1,r2},{r1,r2}}]++;
        }

    }
        while(q--){
            scanf("%s%s",t1+1,t2+1);
            int l,l1=strlen(t1),l2=strlen(t2);
            if(l1!=l2){
                puts("0");
                continue;
            }l=l1;
            int q=0,z=0;
            for(int i=1;i<=l;i++){
                if(t1[i]!=t2[i]){
                    if(!q)q=i;
                    z=i;
                }
            }
            int ans=0;
            long long r11=0,r12=0,r21=0,r22=0;
            for(int j=q;j<=z;j++){
                r11=(r11+t1[j]-'a')*b1%p1;
                r12=(r12+t1[j]-'a')*b2%p2;
                r21=(r21+t2[j]-'a')*b1%p1;
                r22=(r22+t2[j]-'a')*b2%p2;
            }
            if(!p.count({{r11,r12},{r21,r22}})){
                puts("0");
                continue;
            }
            for(int i=1;i<=l;i++){
                re1[i][0]=(re1[i-1][0]+t1[i]-'a')*b1%p1;
                re1[i][1]=(re1[i-1][1]+t1[i]-'a')*b2%p2;
                re2[i][0]=(re2[i-1][0]+t2[i]-'a')*b1%p1;
                re2[i][1]=(re2[i-1][1]+t2[i]-'a')*b2%p2;

            }long long q11=0,q12=0;
            for(int i=q-1;i>=1;i--){
                q11+=c1[q-i]*(t1[i]-'a');
                q11%=p1;
                q11+=c2[q-i]*(t1[i]-'a');
                q11%=p2;
                long long h11=0,h12=0;
                for(int j=z+1;j<=l;j++){
                    h11=(h11+t1[j]-'a')*b1%p1;
                    h12=(h12+t1[j]-'a')*b2%p2;
                    if(p[{{r11,r12},{r21,r22}}].count({{q11,q12},{h11,h12}})){
                        ans+=p[{{r11,r12},{r21,r22}}][{{q11,q12},{h11,h12}}];
                    }
                }
            }
            printf("%d\n",ans);
        }

    return 0;
}
