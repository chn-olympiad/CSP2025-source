#include<bits/stdc++.h>
using namespace std;
int t,n,ans,aa,bb,cc;
int abc[4];
struct st{
    int a,b,c,m,now;
}p[300010];
bool cmp(st a,st b){
    return a.m>b.m;
}
int in[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(in,0,sizeof(in));
        ans=0;
        cin>>n;
        abc[1]=0;
        abc[2]=0;
        abc[3]=0;
        for(int i=1;i<=n;i++){

            cin>>aa>>bb>>cc;
            p[i].a=aa;

            p[i].b=bb;
            p[i].c=cc;
            p[i].m=max({p[i].a,p[i].b,p[i].c});
            ans+=p[i].m;
            if(p[i].a==p[i].m){
                abc[1]++;
                p[i].now=1;
            }
            else if(p[i].b==p[i].m){
                abc[2]++;
                p[i].now=2;
            }
            else if(p[i].c==p[i].m){
                abc[3]++;
                p[i].now=3;
            }

        }
        int ch=0;
        if(abc[1]>n/2){
            for(int i=n;i>=1;i--){
                if(p[i].now==1){
                    ch++;
                    in[ch]=p[i].m-max(p[i].b,p[i].c);
                }

            }
        }
        if(abc[2]>n/2){
            for(int i=n;i>=1;i--){
                if(p[i].now==2){
                    ch++;
                    in[ch]=p[i].m-max(p[i].a,p[i].c);
                }
            }
        }
        if(abc[3]>n/2){
            for(int i=n;i>=1;i--){
                if(p[i].now==3){
                    ch++;
                    in[ch]=p[i].m-max(p[i].a,p[i].b);
                }
            }
        }
        if(ch!=0){
            sort(in+1,in+1+ch);
            for(int i=1;i<=max({abc[1],abc[2],abc[3]})-n/2;i++){
                ans-=in[i];
            }
        }

        cout<<ans<<'\n';
    }

    return 0;
}
