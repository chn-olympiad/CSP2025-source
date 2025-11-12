#include<bits/stdc++.h>
using namespace std;

string s;

priority_queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            q.push(s[i]-'1'+1);
        }
    }

    while(!q.empty())
    {
        cout<<q.top();
        q.pop();
    }
    cout<<endl;

    return 0;
}
