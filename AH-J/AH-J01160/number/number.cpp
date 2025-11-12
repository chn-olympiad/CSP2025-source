#include<bits/stdc++.h>
using namespace std;

string s;
long long a[1000000+5],u=1;

bool cmp(long long a,long long b){
    return a>b;
}

int main(void){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",&s);
    for(int i=1;i<=s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[u]=a[i]-'0';
            u++;
        }
    }
    sort(a+1,a+1+u,cmp);
    for(int i=1;i<=u;i++){
        printf("%lld",a[i]);
    }
    return 0;
}
