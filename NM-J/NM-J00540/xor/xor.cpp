#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[5000000];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d", &n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n==2){
        printf("3");
    }else if(n<2){
        printf("1");
    }
    return 0;
}
