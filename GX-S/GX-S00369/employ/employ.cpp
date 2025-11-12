# include<bits/stdc++.h>
using namespace std;

int mod = 998244353;
int n, m, arr[505], ans, k;
char s[505];
void DFS(int sum, int num, int post, int gu, int book[]){
    if(num == n){
        return;
    }
    if(gu < arr[post] && s[num] == '1'){
        sum++;
    }
    else{
        gu++;
    }
    book[post] = 1;
    if(sum >= m){
        ans = (ans+1) % mod;
        return;
    }
    for ( int i = 0 ; i < n ; i++ ){
        if(book[i] == 0){
            book[i] = 1;
            DFS(sum,num+1,i,gu,book);
            book[i] = 0;
        }
    }
    book[post] = 0;
    return;
}

int main(void){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    int book[505];
    for ( int i = 0; i < n ; i++ ){
        scanf("%d", &arr[i]);
    }
    for ( int i = 0 ; i < n ; i++ ){
        if(s[i] == '1'){
            k++;
        }
        book[i] = 0;
    }
    if(k < m){
        printf("0");
        return 0;
    }
    for ( int i = 0 ; i < n ; i++ ){
        DFS(0,0,i,0,book);
    }
    printf("%d", ans%mod);
    return 0;
}
