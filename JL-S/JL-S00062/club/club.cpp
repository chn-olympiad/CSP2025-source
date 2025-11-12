#include<bits/stdc++.h>
using namespace std;
struct st{
    int a,b,c,z;
};
bool cmp(st x,st y){
    return x.z>y.z;
}
int n,t,a,b,c,ans1,ans2,ans3;
st s[100001];
void f(){
    a=0;b=0;c=0;ans1=0;ans2=0;ans3=0;
    for(int i=1;i<=n;i++){
        s[i].a=0;
        s[i].b=0;
        s[i].c=0;
        s[i].z=0;
    }
    return;
}
void ch2(){
    int maxn=0;
    maxn=max(maxn,s[1].a+s[2].b);
    maxn=max(maxn,s[1].a+s[2].c);
    maxn=max(maxn,s[1].b+s[2].a);
    maxn=max(maxn,s[1].b+s[2].c);
    maxn=max(maxn,s[1].c+s[2].a);
    maxn=max(maxn,s[1].c+s[2].b);
    printf("%d\n",maxn);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&s[i].a);
            scanf("%d",&s[i].b);
            scanf("%d",&s[i].c);
            s[i].z=max(max(s[i].a,s[i].b),s[i].c);
        }
        if(n==2){
            ch2();
            continue;
        }
        sort(s+1,s+n+1,cmp);
        for(int i=1;i<=n;i++){
            if((s[i].a>=s[i].b)&&(s[i].a>=s[i].c)&&a+1<=n/2){
                ans1+=s[i].a;
                a++;
            }else if((s[i].b>=s[i].a)&&(s[i].b>=s[i].c)&&b+1<=n/2){
                ans2+=s[i].b;
                b++;
            }else if((s[i].c>=s[i].b)&&(s[i].c>=s[i].a)&&c+1<=n/2){
                ans3+=s[i].c;
                c++;
            }else if(((s[i].a>=s[i].b)||(s[i].a>=s[i].c))&&a+1<=n/2&&s[i].a>=1.0*ans1/a){
                ans1+=s[i].a;
                a++;
            }else if(((s[i].b>=s[i].a)||(s[i].b>=s[i].c))&&b+1<=n/2&&s[i].b>=1.0*ans2/b){
                ans2+=s[i].b;
                b++;
            }else if(((s[i].c>=s[i].b)||(s[i].c>=s[i].a))&&c+1<=n/2&&s[i].c>=1.0*ans3/c){
                ans3+=s[i].c;
                c++;
            }else if(s[i].a>=1.0*ans1/a&&a+1<=n/2){
                ans1+=s[i].a;
                a++;
            }else if(s[i].b>=1.0*ans2/b&&b+1<=n/2){
                ans2+=s[i].b;
                b++;
            }else if(s[i].a>=1.0*ans3/c&&c+1<=n/2){
                ans3+=s[i].c;
                c++;
            }else if(a+1<=n/3){
                ans1+=s[i].a;
                a++;
            }else if(b+1<=n/3){
                ans2+=s[i].b;
                b++;
            }else if(c+1<=n/3){
                ans3+=s[i].c;
                c++;
            }else if(c+1<=n/2){
                ans3+=s[i].c;
                c++;
            }else if(b+1<=n/2){
                ans2+=s[i].b;
                b++;
            }else if(a+1<=n/2){
                ans1+=s[i].a;
                a++;
            }
        }
        printf("%d\n",ans1+ans2+ans3);
        f();
    }
    return 0;
}
