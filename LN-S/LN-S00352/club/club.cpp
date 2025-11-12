#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct staff{
    int a,b;
    int ai,bi;
};
int t;
int n;
staff f[maxn];
int x,y,z;
int ans;
int s[4];
bool mycmp(staff x,staff y){
    return x.a-x.b>y.a-y.b;
}
void ff(int x,int y,int z){
    if(s[x]<s[y]&&s[x]<s[z]) s[x]++;
    if(s[y]<s[z]&&s[y]<s[z]) s[y]++;
    else s[z]++;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            cin>>x>>y>>z;
            if(x==y&&y==z) f[i].ai=f[i].bi=0,f[i].a=f[i].b=x;
            if(x==y&&x<z) f[i].a=z,f[i].ai=3,f[i].b=x,f[i].bi=0;
            if(z==x&&z<y) f[i].a=y,f[i].ai=2,f[i].b=z,f[i].bi=0;
            if(y==z&&y<x) f[i].a=x,f[i].ai=1,f[i].b=y,f[i].bi=0;
            if(x>y){
                if(x>z){
                    f[i].a=x,f[i].ai=1;
                    if(y>z) f[i].b=y,f[i].bi=2;
                    else f[i].b=z,f[i].bi=3;
                }
                else{
                    f[i].a=z,f[i].ai=3;
                    f[i].b=x,f[i].bi=1;
                }
            }
            else{
                if(y>z){
                    f[i].a=y,f[i].ai=2;
                    if(x>z) f[i].b=x,f[i].bi=1;
                    else f[i].b=z,f[i].bi=3;
                }
                else{
                    f[i].a=z,f[i].ai=3;
                    f[i].b=y,f[i].bi=2;
                }
            }
        }
        sort(f+1,f+n+1,mycmp);
        ans=0;
        memset(s,0,sizeof(s));
        s[0]=n;
        for(int i=1;i<=n;i++){
            staff t=f[i];
            if(!t.ai) ans+=t.a,ff(1,2,3);
            else if(t.a==t.b) ans+=t.a,ff(0,t.ai,t.bi);
            else{
                if(s[t.ai]<n/2) ans+=t.a,s[t.ai]++;
                else{
                    ans+=t.b;
                    if(!t.bi) ff(0,(t.ai+1)%3,(t.ai+2)%3);
                    else s[t.bi]++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
