#include<bits/stdc++.h>
using namespace std;
long long n,k;
int num[5000006],sum=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    if(k==1){
        for(int i=1;i<=n;i++){
            if(num[i]==1){
                sum++;
            }
        }
        printf("%d",sum);
    }else{//k==0
        for(int i=1;i<=n;i++){
            if(num[i]==0){
                sum++;
            }
        }
        printf("%d",sum);
    }
    return 0;
}
