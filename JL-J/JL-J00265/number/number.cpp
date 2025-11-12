#include <bits/stdc++.h>
using namespace std;
int x=1,n=0;
char a[10000000];
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
        if('0'<=s[i]&&s[i]<='9'){
            a[x]=s[i];
            x++;
        }
    for(int i=1;i<=s.size();i++)
        if(a[i]!=' ')
            n++;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        cout<<a[i];
    freopen("number.out","w",stdout);
    return 0;
}
