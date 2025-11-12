#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e6+5;
char c[maxn];
int a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",c+1);
    int len=strlen(c+1);
    for(int i=1;i<=len;i++){
        if(c[i]>='0'&&c[i]<='9'){
            a[c[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)for(int j=1;j<=a[i];j++)printf("%d",i);
    printf("\n");
    return 0;
}
