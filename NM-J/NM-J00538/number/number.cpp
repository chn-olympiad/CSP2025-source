#include<bits/stdc++.h>
using namespace std;
char s[1000001];
priority_queue<int>a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s + 1);
    int n = strlen(s + 1);
    for(int i = 1;i <= n;++i)
        if(s[i] >= '0' && s[i] <= '9')
            a.push(s[i] - '0');
    while(!a.empty()){
        printf("%d",a.top());
        a.pop();
    }
    return 0;
}
