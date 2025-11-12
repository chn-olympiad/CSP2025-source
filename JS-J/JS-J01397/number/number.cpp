#include <bits/stdc++.h>
using namespace std ;
const long long N = 1e6 + 10 ;
char c[N] ;
int main(){
    freopen("number.in","r",stdin) ;
    freopen("number.out","w",stdout) ;
    scanf("%s",c) ;
    long long len = strlen(c) ;
    string s ="";
    for(int i =0 ; i < len; i++){
        if(c[i] >= '0' && c[i] <='9'){
            s += c[i] ;
        }
    }
    sort(s.begin(),s.end()) ;
    reverse(s.begin(),s.end()) ;
   for(auto d : s){
    printf("%c",d) ;
   }
    return 0;
}
