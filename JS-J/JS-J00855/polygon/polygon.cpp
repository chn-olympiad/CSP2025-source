#include<bits/stdc++.h>
using namespace std;
long long n,cnt1;
int a[5050];

int dfs(int S,int Max,int all){
    Max=max(Max,a[S]);
    all+=a[S];
    if(all>(Max*2)){
        cnt1++;
    }
    for(int i=S+1;i<=n;i++){
        dfs(i,Max,all);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        dfs(i,a[i],0);
    }
    printf("%d",cnt1);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
