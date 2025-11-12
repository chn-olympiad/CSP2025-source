#include<bits/stdc++.h>
using namespace std;
const int MAX= 5010;
int A[MAX],ans,n,ar[MAX],ai;
bool used[MAX];
bool check(int len){
    // printf("check\n");
    int m=-1,sum=0;
    for(int i = 1;i<len;i++){
        // printf("%d ",ar[i]);
        m=max(m,ar[i]);
        sum+=ar[i];    
    }
    // printf("\n");
    if(sum>m*2) return 1;
    return 0;
}
void search(int t,int now){
    // printf("searching\n");
    if(t==0 and check(now)) ans++; 
    else{
        for(int i = now;i<=n;i++){
            if(!used[i]){
                // printf("i:%d,t:%d\n",i,t);
                used[i]=1;
                ar[now++]=A[i];
                search(t-1,i+1);
                now--;
                used[i]=0;
            }
        }
    }
}
void solve(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    for(int i = 3;i<=n;i++)
        search(i,1);
    printf("%d",ans);

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    solve();
    return 0;
}