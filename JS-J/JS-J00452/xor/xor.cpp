#include"bits/stdc++.h"
using namespace std;

int n,k,q;
int arr[500010];
int yh[500010];


int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    scanf("%d""%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        yh[i]=arr[i] ^- yh[i-1];
    }

    for(int r=0;r<n;r++){
        for(int l=0;l<r;l++){
            if(yh[r]-yh[l-1] == k){
                q++;
            }
        }
    }

    printf("%d",q);
    return 0;
}
