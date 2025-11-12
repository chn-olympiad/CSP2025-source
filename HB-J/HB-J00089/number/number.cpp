#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000010
int arr[MAXN],cnt,n,ans[MAXN];
char s[MAXN];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++)
        if(s[i]>='0' && s[i]<='9') arr[++cnt]=s[i]-'0';
    for(int i=1;i<=cnt;i++) ans[arr[i]]++;
    for(int i=9;i>=0;i--)
        for(int j=1;j<=ans[i];j++) printf("%d",i);
    return 0;
}
