#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
bool cmp(int a , int b){
    return a > b;
}
int c,r;
int main(){
    freopen("seat.in" , "r" ,stdin);
    freopen("seat.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i ++){
        cin >> a[i];
    }
    int num = a[1];
    sort(a+1 , a+n*m+1 , cmp);
    for(int i = 1;i <= n*m;i ++){
        if(a[i] == num)
            num = i;
    }
    int cnt = num/2/n;
    c += cnt*2 + 1;
    r = cnt*2*n;
    num -= r;
    if(num <= n){
        printf("%d %d" , c , num);
    }
    else
        printf("%d %d" , c+1 ,2*n-num+1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
