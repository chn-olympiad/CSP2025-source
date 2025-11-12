#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
char s[N];
ll a[200];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<strlen(s);i++){
        a[s[i]]++;
        if(s[i]==57) putchar('9');
    }
    for(int i=56;i>=48;i--)
        while(a[i]--)
            putchar(i);
}
