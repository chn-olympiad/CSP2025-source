#include <bits/stdc++.h>
using namespace std;
char a[1000007];
int b[1000007];
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", a);
    int n=strlen(a), ct=0;
    for(int i=0; i<n; ++i){
        if(a[i]>='0' && a[i]<='9'){
            b[++ct]=a[i]-'0';
        }
    }
    sort(b+1, b+1+ct);
    for(int i=ct; i>=1; --i){
        printf("%d", b[i]);
    }
}
