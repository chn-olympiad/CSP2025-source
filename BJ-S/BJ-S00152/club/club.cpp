#include<bits/stdc++.h>
using namespace std;
int n,T;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    priority_queue<long long> q1,q2,q3;
    long long a1,a2,a3;
    long long x1,x2,x3;
    long long ans,tmp;
    while(T--){
        scanf("%d",&n);
        ans=0;
        x1=0,x2=0,x3=0;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a1,&a2,&a3);
            if(a1>=a2&&a2>=a3) ans+=a1,q1.push(a2-a1),x1++;
            else if(a1>=a3&&a3>=a2) ans+=a1,q1.push(a3-a1),x1++;
            else if(a2>=a1&&a1>=a3) ans+=a2,q2.push(a1-a2),x2++;
            else if(a2>=a3&&a3>=a1) ans+=a2,q2.push(a3-a2),x2++;
            else if(a3>=a1&&a1>=a2) ans+=a3,q3.push(a1-a3),x3++;
            else if(a3>=a2&&a2>=a1) ans+=a3,q3.push(a2-a3),x3++;
        }
        tmp=x1;
        while(tmp>n/2){
            ans+=q1.top(),q1.pop();
            tmp--;
        }
        while(!q1.empty()) q1.pop();
        tmp=x2;
        while(tmp>n/2){
            ans+=q2.top(),q2.pop();
            tmp--;
        }
        while(!q2.empty()) q2.pop();
        tmp=x3;
        while(tmp>n/2){
            ans+=q3.top(),q3.pop();
            tmp--;
        }
        while(!q3.empty()) q3.pop();
        printf("%lld\n",ans);
    }
    return 0;
}
