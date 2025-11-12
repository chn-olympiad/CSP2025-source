#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<int,vector<int>,less<int> >q;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]>='0'&&s[i]<='9')

        {
            q.push((int)(s[i]-'0'));
        }
    }
    bool flag=1;
    while(!q.empty())
    {
        int x=q.top();
        q.pop();
        printf("%d",x);
    }
    return 0;
}
