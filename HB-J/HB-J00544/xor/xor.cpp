#include <cstdio>

int R[500000];

int hhh(int l,int r,int k){
    if (l == r) {
        return 0;
    }

    int caluK = R[l];

    for (int i = l+1; i < r; i++) {
        if (caluK == k) {
            return 1 + hhh(i,r,k);
        }

        caluK ^= R[i];
    }
    if (caluK == k) {
        return 1;
    }

    return hhh(l+1,r,k);
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; i++) {
         scanf("%d",&R[i]);
    }
    printf("%d",hhh(0,n,k));
    return 0;
}
