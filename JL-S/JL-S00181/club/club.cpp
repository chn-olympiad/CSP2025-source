#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
    int a,b,c;
}s1[N],s2[N],s3[N];
int t,len1,len2,len3,n,ans,u,v,w;
bool cmp(node x,node y){
    return x.b>y.b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        len1=0,len2=0,len3=0,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i=-~i){
            scanf("%d%d%d",&u,&v,&w);
            if(u>max(v,w)) s1[++len1].a=u,s1[len1].b=min(u-v,u-w),s1[len1].c=max(v,w);
            else if(v>max(u,w)) s2[++len2].a=v,s2[len2].b=min(v-u,v-w),s2[len2].c=max(u,w);
            else if(w>max(u,v)) s3[++len3].a=w,s3[len3].b=min(w-u,w-v),s3[len3].c=max(u,v);
            else ans+=max(u,max(v,w));
        }
        if(len1>n/2){
            sort(s1+1,s1+1+len1,cmp);
            for(int i=1;i<=n/2;i=-~i) ans+=s1[i].a;
            for(int i=n/2+1;i<=len1;i=-~i) ans+=s1[i].c;
            for(int i=1;i<=len2;i=-~i) ans+=s2[i].a;
            for(int i=1;i<=len3;i=-~i) ans+=s3[i].a;
        }
        else if(len2>n/2){
            sort(s2+1,s2+1+len2,cmp);
            for(int i=1;i<=n/2;i=-~i) ans+=s2[i].a;
            for(int i=n/2+1;i<=len2;i=-~i) ans+=s2[i].c;
            for(int i=1;i<=len1;i=-~i) ans+=s1[i].a;
            for(int i=1;i<=len3;i=-~i) ans+=s3[i].a;
        }
        else if(len3>n/2){
            sort(s3+1,s3+1+len3,cmp);
            for(int i=1;i<=n/2;i=-~i) ans+=s3[i].a;
            for(int i=n/2+1;i<=len3;i=-~i) ans+=s3[i].c;
            for(int i=1;i<=len1;i=-~i) ans+=s1[i].a;
            for(int i=1;i<=len2;i=-~i) ans+=s2[i].a;
        }
        else{
            for(int i=1;i<=len1;i=-~i) ans+=s1[i].a;
            for(int i=1;i<=len2;i=-~i) ans+=s2[i].a;
            for(int i=1;i<=len3;i=-~i) ans+=s3[i].a;
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
