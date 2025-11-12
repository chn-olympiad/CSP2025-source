#include<bits/stdc++.h>
using namespace std;
struct p{
    long long a,b,c;
};
struct ma{
    long long m1,m2;
};
bool cmp(p x,p y){
    return x.a>y.a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t=0;
    scanf("%d",&t);
    while(t){
        long long n=0,ans=0;
        ma dp[200005]={};
        scanf("%d",&n);
        vector<p> v1={};
        for(int i=0;i<n;i++){
            p k={};
            scanf("%lld%lld%lld",&k.a,&k.b,&k.c);
            v1.push_back(k);
        }
        for(int i=0;i<n;i++){
            p k=v1[i];
            //cout<<k.a<<" "<<k.b<<" "<<k.c<<"\n";
        }
        long long s[3]={};
        //long long m1=0,m2=0;
        dp[0].m1=max(v1[0].a,v1[0].b);
        dp[0].m2=max(v1[0].c,v1[0].b);
        if(dp[0].m1==dp[0].m2){
            dp[0].m2=max(v1[0].a,v1[0].c);
        }
        if(dp[0].m1<dp[0].m2){
                int k=dp[0].m1;
                dp[0].m1=dp[0].m2;
                dp[0].m2=k;
        }
        if(v1[0].a==dp[0].m1 && s[0]<=n/2){
            s[0]++;
        }else if(v1[0].b==dp[0].m1 && s[1]<=n/2){
            s[1]++;
        }else if(v1[0].b==dp[0].m1 && s[2]<=n/2){
            s[2]++;
        }
        //cout<<m1<<" "<<m2<<"\n";
        //cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<"\n";
        //dp[0]=m1;
        for(int i=1;i<n;i++){
            int f=0,g=0,h=0;
            if(v1[i].a==dp[i].m2 && s[0]<=n/2){
                f=0;
            }else if(v1[0].b==dp[0].m2 && s[1]<=n/2){
                f=1;
            }else if(v1[0].b==dp[0].m2 && s[2]<=n/2){
                f=2;
            }else{
                f=2;
            }
            if(v1[i].a==dp[i].m1 && s[0]<=n/2){
                g=0;
            }else if(v1[0].b==dp[0].m1 && s[1]<=n/2){
                g=1;
            }else if(v1[0].b==dp[0].m1 && s[2]<=n/2){
                g=2;
            }else{
                g=2;
            }
            dp[i].m1=max(v1[i].a,v1[i].b);
            dp[i].m2=max(v1[i].c,v1[i].b);
            if(dp[i].m1==dp[i].m2){
                dp[i].m2=max(v1[i].a,v1[i].c);
            }
            if(dp[i].m1<dp[i].m2){
                int k=dp[i].m1;
                dp[i].m1=dp[i].m2;
                dp[i].m2=k;
            }
            if(v1[i].a==dp[i].m2 && s[0]<=n/2){
                h=0;
            }else if(v1[0].b==dp[0].m2 && s[1]<=n/2){
                h=1;
            }else if(v1[0].b==dp[0].m2 && s[2]<=n/2){
                h=2;
            }else{
                h=2;
            }
            //cout<<m1<<" "<<m2<<"\n";

            if(v1[i].a==dp[i].m1 && s[0]<=n/2){
                s[0]++;
                if(dp[i-1].m1+dp[i].m1>dp[i-1].m2+dp[i].m1){
                    dp[i].m1=dp[i-1].m1+dp[i].m1;
                    dp[i].m2=dp[i-1].m1+dp[i].m2;
                }else{
                    dp[i].m1=dp[i-1].m2+dp[i].m1;
                    dp[i].m2=dp[i-1].m2+dp[i].m2;
                    s[f]++;
                    s[g]--;
                }
            }else if(v1[i].b==dp[i].m1 && s[1]<=n/2){
                s[1]++;
                if(dp[i-1].m1+dp[i].m1>dp[i-1].m2+dp[i].m1){
                    dp[i].m1=dp[i-1].m1+dp[i].m1;
                    dp[i].m2=dp[i-1].m1+dp[i].m2;
                }else{
                    dp[i].m1=dp[i-1].m2+dp[i].m1;
                    dp[i].m2=dp[i-1].m2+dp[i].m2;
                    s[f]++;
                    s[g]--;
                }

            }else if(v1[i].c==dp[i].m1 && s[1]<=n/2){
                s[2]++;
                if(dp[i-1].m1+dp[i].m1>dp[i-1].m2+dp[i].m1){
                    dp[i].m1=dp[i-1].m1+dp[i].m1;
                    dp[i].m2=dp[i-1].m1+dp[i].m2;
                }else{
                    dp[i].m1=dp[i-1].m2+dp[i].m1;
                    dp[i].m2=dp[i-1].m2+dp[i].m2;
                    s[f]++;
                    s[g]--;
                }



            }else if(v1[i].a==dp[i].m1 && s[0]>n/2){
                s[h]++;
                if(dp[i-1].m1+dp[i].m2>dp[i-1].m2+dp[i].m2){
                    dp[i].m1=dp[i-1].m1+dp[i].m2;
                    dp[i].m2=dp[i-1].m1+dp[i].m2;
                }else{
                    dp[i].m1=dp[i-1].m2+dp[i].m2;
                    dp[i].m2=dp[i-1].m2+dp[i].m2;
                    s[f]++;
                    s[g]--;
                }
            }else if(v1[i].b==dp[i].m1 && s[1]>n/2){
                s[h]++;
                if(dp[i-1].m1+dp[i].m2>dp[i-1].m2+dp[i].m2){
                    dp[i].m1=dp[i-1].m1+dp[i].m2;
                    dp[i].m2=dp[i-1].m1+dp[i].m2;
                }else{
                    dp[i].m1=dp[i-1].m2+dp[i].m2;
                    dp[i].m2=dp[i-1].m2+dp[i].m2;
                    s[f]++;
                    s[g]--;
                }
            }else if(v1[i].c==dp[i].m1 && s[2]>n/2){
                s[h]++;
                if(dp[i-1].m1+dp[i].m2>dp[i-1].m2+dp[i].m2){
                    dp[i].m1=dp[i-1].m1+dp[i].m2;
                    dp[i].m2=dp[i-1].m1+dp[i].m2;
                }else{
                    dp[i].m1=dp[i-1].m2+dp[i].m2;
                    dp[i].m2=dp[i-1].m2+dp[i].m2;
                    s[f]++;
                    s[g]--;
                }
            }
            //cout<<dp[i].m1<<" "<<dp[i].m2;
            ans+=dp[i].m1;
        }
        printf("%d\n",dp[n-1].m1);
        t--;
    }
    return 0;
}
