#include<bits/stdc++.h>
using namespace std;
long long n,s[10];
string st;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>st;
    n=st.size();
    st=" "+st;
    for(long long i=1;i<=n;i++)
    {
        if(st[i]>='0' && st[i]<='9')
        {
            s[st[i]-'0']++;
        }
    }
    for(long long i=9;i>=0;i--)
    {
        for(long long j=1;j<=s[i];j++)
        {
            cout<<i;
        }
    }
    return 0;
}
