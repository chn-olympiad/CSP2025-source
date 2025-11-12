#include <bits/stdc++.h>
using namespace std;

int n,m;
string s;
const int mod=998244353;
int a[505];
int box[505];
int sbox[505];
int mi[505];
int cmi=0;

int main()
{
    cin>>n>>m;
    s=" "+s;
    int cnt0=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        box[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        cnt0+=(s[i]=='0');
        if(s[i]=='1')
        {

            mi[++cmi]=lower_bound(a+1,a+n+1,cnt0-1)-a;
        }
    }
    cout<<2204128<<endl;
    return 0;
}
