#include<bits/stdc++.h>
using namespace std;
char a[1000010];
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size(),cnt=0;
    for(int i=0;i<n;i++)
        if(s[i]>='0'&&s[i]<='9')
            a[++cnt]=s[i];
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
        printf("%c",a[i]);

    return 0;
}
