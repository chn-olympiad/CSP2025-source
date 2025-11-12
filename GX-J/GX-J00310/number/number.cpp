#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> pq;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
            pq.push(s[i]-48);
    }
    while(!pq.empty())
    {
        cout<<pq.top();
        pq.pop();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
