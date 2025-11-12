#include<bits/stdc++.h>
#define N 1000010
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
string s;
int a[N],k=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++)
        if(isdigit(s[i]))
            a[++k]=s[i]-'0';
    sort(a+1,a+k+1,greater<int>());
    for(int i=1;i<=k;i++)
        cout<<a[i];
    return 0;
}
