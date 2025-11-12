#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],s[100005],ans=-1;
bool b=1;
void dfs(long long num1,long long num2,long long num3,long long sum,long long cnt){
    if(num1>n/2)return;
    if(num2>n/2)return;
    if(num3>n/2)return;
    if(num1+num2+num3==n){
        if(sum>ans)ans=sum;
        return;
    }
    if(a[cnt+1][1]!=0)dfs(num1+1,num2,num3,sum+a[cnt+1][1],cnt+1);
    if(a[cnt+1][2]!=0)dfs(num1,num2+1,num3,sum+a[cnt+1][2],cnt+1);
    if(a[cnt+1][3]!=0)dfs(num1,num2,num3+1,sum+a[cnt+1][3],cnt+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        ans=-1;
        b=1;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%lld",&a[i][j]);
            }
            s[i]=a[i][1];
            if(a[i][2]!=0||a[i][3]!=0)b=0;
        }
        if(b==1){
            sort(s+1,s+1+n);
            long long res=0;
            for(int i=n;i>n/2;i--){
                res+=s[i];
            }
            printf("%lld\n",res);
            continue;
        }
        else {
            dfs(0,0,0,0,0);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
