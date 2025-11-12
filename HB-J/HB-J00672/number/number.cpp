#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    priority_queue<int> q;
    for(int i=0;i<a.size();i++) if(a[i]>='0'&&a[i]<='9') q.push((int)(a[i]-'0'));
    while(q.size())
    {
        cout<<q.top();
        q.pop();
    }
    return 0;
}

