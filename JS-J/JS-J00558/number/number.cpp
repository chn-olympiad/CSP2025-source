#include <bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.length();
    for(int i=0;i<=len;i++){
        if(0<=s[i]-'0'&&s[i]-'0'<=9)a[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=a[i];j>0;j--){
            printf("%d",i);
        }
    }
    return 0;
}
