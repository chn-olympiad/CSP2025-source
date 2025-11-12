#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll cnt=0;
priority_queue<char> pq;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    for(ll i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            pq.push(s[i]);
            cnt++;
        }
    }
    for(ll i=1;i<=cnt;i++)
    {
        cout<<pq.top();
        pq.pop();
    }
    return 0;
}
