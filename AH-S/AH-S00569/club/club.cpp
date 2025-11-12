#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,T,s1,s2,s3,ans;
struct node{
    int a,b,c,w,r;
}t[100010];
bool cmp(node x,node y){
    return x.r<y.r;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        s1=s2=s3=ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>t[i].a>>t[i].b>>t[i].c;
            if(t[i].a>=t[i].b&&t[i].a>=t[i].c){
                ans+=t[i].a;
                t[i].w=1;
                s1++;
                t[i].r=min(t[i].a-t[i].b,t[i].a-t[i].c);
            }else if(t[i].b>=t[i].a&&t[i].b>=t[i].c){
                ans+=t[i].b;
                t[i].w=2;
                s2++;
                t[i].r=min(t[i].b-t[i].a,t[i].b-t[i].c);
            }else{
                ans+=t[i].c;
                t[i].w=3;
                s3++;
                t[i].r=min(t[i].c-t[i].a,t[i].c-t[i].b);
            }
        }
        sort(t+1,t+n+1,cmp);
        if(s1>n/2){
            for(int i=1;i<=n;i++){
                if(t[i].w==1){
                    s1--;
                    ans-=t[i].r;
                }
                if(s1<=n/2)break;
            }
        }else if(s2>n/2){
            for(int i=1;i<=n;i++){
                if(t[i].w==2){
                    s2--;
                    ans-=t[i].r;
                }
                if(s2<=n/2)break;
            }
        }else if(s3>n/2){
            for(int i=1;i<=n;i++){
                if(t[i].w==3){
                    s3--;
                    ans-=t[i].r;
                }
                if(s3<=n/2)break;
            }
        }
        for(int i=1;i<=n;i++)t[i].a=t[i].b=t[i].c=t[i].w=t[i].r=0;
        cout<<ans<<endl;
    }
    return 0;
}
