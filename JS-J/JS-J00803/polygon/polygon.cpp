#include <iostream>
using namespace std;
int n;
int arr[5005];
int ans=0;
long long fl_ans=0;
void dfs(int k,int k_front,int sum,int maxx,int end__){
    if(k>end__){
            //cout<<k-1<<" "<<sum<<" "<<maxx<<endl;
        if(sum>2*maxx){
            ans++;
        }
        return;
    }
    for(int i=k_front;i<=n;i++){
        dfs(k+1,i+1,sum+arr[i],max(maxx,arr[i]),end__);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=3;i<=n;i++){
        dfs(1,1,0,0,i);
        fl_ans+=ans;
        ans=0;
    }
    printf("%lld",fl_ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
