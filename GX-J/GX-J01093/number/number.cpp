#include <bits/stdc++.h>
using namespace std;
int b[10000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a=0;
    string s;
    cin>>s;
    for(int i=0;i<=s.length()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            b[a]+=s[i]-'0';
            a++;
        }
    }
    sort(b+a+1,b+1);
    for(int i=0;i<=a;i++){
        cout<<b[i];
    }
    return 0;
}
