#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int n;
char s[N];
vector<int> v;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);  
    scanf("%s",s + 1);
    n = strlen(s + 1);
    for (int i = 1;i <= n;i++){
        if ('0' <= s[i] && s[i] <= '9') v.emplace_back(s[i] - '0');
    }
    sort(v.begin(),v.end(),greater<int>());
    for (int i : v) printf("%d",i);
    printf("\n");
    return 0;
}