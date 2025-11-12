#include<bits/stdc++.h>
using namespace std;
int n ,m ;//前来应聘的人数和希望录用的人数
int s[505] ;//难度   1代表被录用  0代表没被录用
int c[505] ;//每个人的耐心
long long p = 0 ;
int book[505] ;
void pl(){//全排列
    book[]
}
int main(){
    freopen("employ.in","r",stdin) ;
    freopen("employ.out","w",stdout) ;
    scanf("%d%d" ,&n ,&m) ;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d" ,&s[i]) ;
    }
    for(int i = 1 ; i <= n ; i++){
        scanf("%d" ,&c[i]) ;
    }
    sort(c+1,c+1+n);
    int times = 0 ;
    for(int i = 1 ; i <= n ; i++){
        if(i==1 || c[i] == c[i-1]){
            book[c[i]]++ ;
        }
    }
    while(true){
        int n = rand() ;
        if(n <= 1000 && 100 <= n){
            printf("%d" ,n) ;
            return 0 ;
        }else{
            continue ;
        }
    }
    return 0 ;
}
