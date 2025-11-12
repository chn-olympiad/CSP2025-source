#include <bits/stdc++.h>
using namespace std;

char s[100010];
int a[100010];
int n = 0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s + 1);
    int l = strlen(s + 1);
    int j = 1;
    for(int i = 1;i <= l;i++){
        if(s[i] - '0' <= 9){
            a[j] = s[i] - '0';
            n++;
            j++;
        }
    }
    sort(a,a + n + 1);
    for(int i = n;i >= 1;i--){
        printf("%d",a[i]);
    }
    return 0;
}
