#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size(),cnt=0;
    for(int i=0;i<n;i++){
        if('0'<=s[i]&&s[i]<='9')
            a[++cnt]=s[i]-'0';
    }
    stable_sort(a+1,a+n+1,cmp);
    if(a[1]==0) cout<<"0";
    else {
        for(int i=1;i<=cnt;i++)
            printf("%d",a[i]);
    }
    return 0;
}
