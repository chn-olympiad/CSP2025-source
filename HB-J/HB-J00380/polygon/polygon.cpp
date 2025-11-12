#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n,a[5005];
long long ans,re[5000];
long long cal(int x){
    if(re[x]!=0) return re[x];
    long long val=0,add;
    for(int i=1;i<=x;i++){
        add=1;
        for(int j=1;j<=i;j++){
            add*=(x+1-j);
            add/=j;
        }
        val+=add;
        if(val>MOD) val-=MOD;
    }
    while(val>MOD) val-=MOD;
    re[x]=val;
    return val;
}
void dfs(int biggest,int sum,int sta,int cnt){
    if(sum>biggest*2){
        ans++;
        if(cnt>=3){
            int left=max(0,n-sta+1);
            ans+=cal(left);
        }
        else if(cnt==2){
            int left=n-sta;
            if(left<0) ans--;
            else ans+=cal(left);
        }
        if(ans>MOD) ans-=MOD;
        return ;
    }
    for(int i=sta;i<=n;i++){
        dfs(biggest,sum+a[i],i+1,cnt+1);
    }
    return ;
}
bool cmp(int x,int y){
    return x>=y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    if(n<3){
        printf("0");
        return 0;
    }
    if(n>=200){
        long long val=0,add;
        for(int i=3;i<=n;i++){
            add=1;
            for(int j=1;j<=i;j++){
                add*=(n+1-j);
                add/=j;
                while(add>MOD) add-=MOD;
            }
            val+=add;
            if(val>MOD) val-=MOD;
        }
        printf("%lld",val);
        return 0;
    }
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        dfs(a[i],a[i],i+1,1);
    }
    if(ans>MOD) ans-=MOD;
    printf("%lld",ans);
    return 0;
}
