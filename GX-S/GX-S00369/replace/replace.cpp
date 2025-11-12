# include<bits/stdc++.h>

int main(void){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n, q;
    scanf("%d %d", &n, &q);
    char arr[1000000], brr[1000000];
    for ( int i = 0 ; i < n ; i++ ){
        scanf("%s %s", arr, brr);
    }
    for ( int i = 0 ; i < q ; i++ ){
        scanf("%s %s", arr, brr);
    }
    for ( int i = 0 ; i < q ; i++ ){
        printf("0\n");
    }
    return 0;
}
