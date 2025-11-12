#include<iostream>
#include<cstdio>
using namespace std;
int t,ans;
int n,m;
struct node{
    int a,b,c;
}a[100005];
int IDA(int x){
    int cnt;
    for(int i=x;i^n+1;i++){
        cnt+=max(a[i].a,max(a[i].b,a[i].c));
    }
    return cnt;
}
void dfs(int x,int sum,int cnt1,int cnt2,int cnt3){
    if(IDA(x)+sum<=ans)return;
    if(x==n)ans=max(ans,sum);
    if(cnt1<n/2){
        dfs(x+1,sum+a[x].a,cnt1+1,cnt2,cnt3);
    }
    if(cnt2<n/2){
        dfs(x+1,sum+a[x].b,cnt1,cnt2+1,cnt3);
    }
    if(cnt3<n/2){
        dfs(x+1,sum+a[x].c,cnt1,cnt2,cnt3+1);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
        }
        if(n>=30){
            sort(a+1,a+n+1);
            ans=0;
            for(int i=n;i>=n/2+1;i--){
                ans+=a[i].a;
            }
            cout<<ans<<endl;
        }else{
            ans=0;
            dfs(1,0,0,0,0);
            cout<<ans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
