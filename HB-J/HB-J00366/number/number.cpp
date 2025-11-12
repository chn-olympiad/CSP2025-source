#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
char s[N];
int num[N],tot;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s + 1);
    int n = strlen(s + 1);
    for(int i = 1;i <= n;++ i){
        if('0' <= s[i] && s[i] <= '9'){
            num[++ tot] = (int)(s[i] - '0');
        }
    }
    sort(num + 1,num + 1 + tot,greater<int>());
    for(int i = 1;i <= tot;++ i)
        printf("%d",num[i]);
    return 0;
}