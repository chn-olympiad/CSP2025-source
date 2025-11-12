#include<bits/stdc++.h>
using namespace std;
priority_queue<int>pq;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
            pq.push(a[i]-'0');
    }
    while(!pq.empty())
    {
        cout<<pq.top();
        pq.pop();
    }
    return 0;
}
