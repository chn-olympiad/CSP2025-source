#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
int t;
int n,cnt[5];
long long ans=0;
struct number{
    int a,id;
};
struct node{
    number num[5];
}p[N];
bool cmp(number s1,number s2){
    return s1.a>s2.a;
}
bool cmp2(node s1,node s2){
    if(s1.num[1].a!=s2.num[1].a)
        return s1.num[1].a>s2.num[1].a;
    if(s1.num[2].a!=s2.num[2].a)
        return s1.num[2].a>s2.num[2].a;
    return s1.num[2].a>s2.num[2].a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&p[i].num[1].a,&p[i].num[2].a,&p[i].num[3].a);
            p[i].num[1].id=1;
            p[i].num[2].id=2;
            p[i].num[3].id=3;
        }
        for(int i=1;i<=n;i++){
            sort(p[i].num+1,p[i].num+1+3,cmp);
        }
        sort(p+1,p+1+n,cmp2);
        ans=0;
        cnt[1]=cnt[2]=cnt[3]=0;
        long long ans2=0;
        p[n+1].num[1].a=p[n+1].num[2].a=p[n+1].num[3].a=0;
        p[n+1].num[1].id=p[n+1].num[2].id=p[n+1].num[3].id=0;
        for(int i=1;i<=n;i++){
            if(cnt[p[i].num[1].id]<n/2){
                if(p[i].num[1].id!=p[i+1].num[1].id){
                    ans2+=p[i].num[1].a;
                    cnt[p[i].num[1].id]++;
                }else if(p[i].num[1].a>=p[i].num[2].a+p[i+1].num[1].a && cnt[p[i+1].num[1].id]<n/2){
                    ans2+=p[i].num[1].a;
                    cnt[p[i].num[1].id]++;
                }else if(p[i].num[1].a<p[i].num[2].a+p[i+1].num[1].a && cnt[p[i+1].num[1].id]<n/2){
                    ans2+=p[i].num[2].a+p[i+1].num[1].a;
                    cnt[p[i].num[2].id]++;
                    cnt[p[i+1].num[1].id]++;
                    i++;
                }else{
                    ans2+=p[i].num[1].a;
                    cnt[p[i].num[1].id]++;
                }
            }else if(cnt[p[i].num[2].id]<n/2){
                if(p[i].num[2].id!=p[i+1].num[2].id){
                    ans2+=p[i].num[2].a;
                    cnt[p[i].num[2].id]++;
                }else if(p[i].num[2].a>=p[i].num[3].a+p[i+1].num[2].a && cnt[p[i+1].num[2].id]<n/2){
                    ans2+=p[i].num[2].a;
                    cnt[p[i].num[2].id]++;
                }else if(p[i].num[2].a<p[i].num[3].a+p[i+1].num[2].a && cnt[p[i+1].num[2].id]<n/2){
                    ans2+=p[i].num[3].a+p[i+1].num[2].a;
                    cnt[p[i].num[3].id]++;
                    cnt[p[i+1].num[2].id]++;
                    i++;
                }else{
                    ans2+=p[i].num[2].a;
                    cnt[p[i].num[2].id]++;
                }
            }else{
                ans2+=p[i].num[3].a;
                cnt[p[i].num[3].id]++;
            }
        }
        printf("%lld\n",max(ans,ans2));
    }
    return 0;
}
















