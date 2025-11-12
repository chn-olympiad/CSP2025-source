#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define gc getchar_unlocked()
#define pc putchar_unlocked

ll read()//数字快读
{
    char ch=gc;
    int fu=1;
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')fu=-1;
        ch=gc;
    }
    ll x=0;
    while(ch>='0'&&ch<='9')
    {
        x=(x*10)+(ch-'0');
        ch=gc;
    }
    return x*fu;
}
void write(ll x)//数字快写
{
    if(x<0)pc('-'),x=-x;
    if(x>=10)
    {
        write(x/10);
    }
    pc((x%10)+'0');
}
ll a[11];//0-9
//#define DEBUG
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);freopen("number.out","w",stdout);

    string s;cin>>s;
    for(ll i=0;i<s.size();i++)
    {
        char ch=s[i];
        if(ch>='0'&&ch<='9')a[ch-'0']++;
    }
    for(int i=9;i>=0;i--)
    {
        for(ll j=1;j<=a[i];j++)
        {
            cout<<i;
        }
    }
    cout<<endl;
    return 0;
}
