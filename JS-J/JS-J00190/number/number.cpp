#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int a[1000005];
int cnt=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9')a[++cnt]=s[i]-'0';
    }
    sort(a+1,a+1+cnt);
    for(int i=cnt;i>=1;i--)cout << a[i];



    return 0;
}
