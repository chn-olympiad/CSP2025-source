#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1000010];
char s[1000010];
int cur;
int n;
int main(){
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    scanf("%s" , s + 1);
    n = strlen(s + 1);
    for(int i = 1 ; i <= n ; i++){
        if(s[i] >= '0' && s[i] <= '9') a[++cur] = s[i] - '0';
    }
    sort(a + 1 , a + cur + 1);
    for(int i = cur ; i >= 1 ; i--) printf("%d" , a[i]);
    return 0;
}
