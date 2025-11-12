#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[N];
    int n;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[n]=s[i]-'0';
            n++;
        }
    }
    sort(a,a+n,greater<int>());
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
