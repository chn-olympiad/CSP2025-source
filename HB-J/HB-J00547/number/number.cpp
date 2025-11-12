#include <bits/stdc++.h>
using namespace std;
int a[1000005],len,f;
string s;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    len=s.size();
    for(int i=0;i<len;i++)
        if(s[i]>='0' && s[i]<='9')
            a[++f]=int(s[i]-'0');
    sort(a+1,a+1+f,cmp);
    for(int i=1;i<=f;i++)
        printf("%d",a[i]);
    return 0;
}
