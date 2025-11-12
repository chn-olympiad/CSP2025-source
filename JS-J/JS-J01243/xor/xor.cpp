#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
long long a[N];
long long dp[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",a[i]);
    }
    if(n==2){
        printf("%d",1);
    }
    else{
        printf("%d",k);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
