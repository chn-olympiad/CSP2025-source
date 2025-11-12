#include<bits/stdc++.h>
using namespace std;
int n,k,R[500005],B_1[3],ans;
bool A=true,B=true;
int bfs(int i,long long num){
    if(num == k){
        ans++;
        return i;
    }
    if(i == n && num != k) return 1;
    if(num == -1) return bfs(i+1,R[i]);
    return bfs(i+1,R[i]^num);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&R[i]);
        if(R[i] != 1) A=false;
        if(R[i] != 1 && R[i] != 0) B=false;
        else B_1[R[i]]++;
    }
    //
    if(A && k==0){
        printf("%d",n/2);
        return 0;
    }
    if(B){
        if(k==1){
            printf("%d",B_1[1]);
            return 0;
        }else{
            printf("%d",max(B_1[0],B_1[1]/2));
            return 0;
        }
    }
    //
    for(int i=1;i<=n;){
        i+=bfs(i,-1);
    }
    printf("%d",ans);
    return 0;
}
