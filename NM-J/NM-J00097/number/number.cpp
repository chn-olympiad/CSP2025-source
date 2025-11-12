#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e5;
string s;
int a[50005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    stack<char> st1,st2;
    cin>>s;
    int h=0;
    for(int i=0;i<=s.size();i++)
    {
        if('0'<=s[i]&&s[i]<='9'){
            a[h]=s[i];
            n++;
            h++;
        }

    }
    sort(a,a+n+1);
    for(int i=n;i>=0;i--){
        cout<<char(a[i]);
    }

    return 0;
}
