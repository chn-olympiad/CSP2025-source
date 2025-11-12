#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d,w,y,ans,r,e,q[3];
struct str{
    int s[3],s1[3],d,e,f,g;
}s[100010];
bool cmp(str xx,str yy){
    return xx.g>yy.g;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&a);
    while(a--){
        scanf("%lld",&b);
        ans=0,d=b/2;
        q[0]=q[1]=q[2]=0;
        for(int i=0;i<b;i++){
            scanf("%lld%lld%lld",&s[i].s[0],&s[i].s[1],&s[i].s[2]);
            s[i].s1[0]=s[i].s[0];
            s[i].s1[1]=s[i].s[1];
            s[i].s1[2]=s[i].s[2];
            sort(s[i].s1+0,s[i].s1+3);

            s[i].d=max(s[i].s[0],max(s[i].s[1],s[i].s[2]))-s[i].s[0];
            s[i].e=max(s[i].s[0],max(s[i].s[1],s[i].s[2]))-s[i].s[1];
            s[i].f=max(s[i].s[0],max(s[i].s[1],s[i].s[2]))-s[i].s[2];
            s[i].g=max(s[i].d,max(s[i].e,s[i].f));
        }
        sort(s+0,s+b,cmp);
        for(int i=0;i<b;i++){
            w=0;
            if(s[i].s[0]>=s[i].s[1]&&s[i].s[0]>=s[i].s[2]&&q[0]<d)q[0]++,ans+=s[i].s[0],w=1;
            if(s[i].s[1]>=s[i].s[0]&&s[i].s[1]>=s[i].s[2]&&q[1]<d)q[1]++,ans+=s[i].s[1],w=1;
            if(s[i].s[2]>=s[i].s[0]&&s[i].s[2]>=s[i].s[1]&&q[2]<d)q[2]++,ans+=s[i].s[2],w=1;
            if(w==0){
                r=0;
                y=s[i].s1[1];
                for(int j=0;j<3;j++){
                    if(s[i].s[j]==y&&q[j]<d){
                        ans+=s[i].s[j],q[j]++,r=1;
                    }
                }
                if(r==0){
                    y=s[i].s1[0];
                    for(int j=0;j<3;j++){
                        if(s[i].s[j]==y&&q[j]<d){
                            ans+=s[i].s[j],q[j]++,r=1;
                        }
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
