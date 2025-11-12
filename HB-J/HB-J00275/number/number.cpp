#include<bits/stdc++.h>
using namespace std;

int a[1000001],m;

bool cmp(int A,int B){
    return A>B;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]-'0'>=0&&s[i]-'0'<=9)
            a[++m]=s[i]-'0';
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++)
        printf("%d",a[i]);
    return 0;
}
