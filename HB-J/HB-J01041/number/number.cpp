#include<iostream>
#include<cstdio>
using namespace std;
string s;
int a[100];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++)
        if('0'<=s[i]&&s[i]<='9')a[int(s[i]-'0')]++;
    bool flag=false;
    for(int i=9;i>=1;i--)for(int j=1;j<=a[i];j++){cout<<i;flag=true;}
    if(!flag)cout<<0;
    else for(int j=1;j<=a[0];j++)cout<<0;
    return 0;
}
