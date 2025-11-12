#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
        freopen("number.in","r",stdin);
        freopen("number.out","w",stdout);
    string a;
    cin>>a;
    priority_queue<int> sum;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<='9' && a[i]>='0')
        {
            sum.push(a[i]-'0');
        }
    }
    int tmp=sum.size();
    for(int i=0;i<tmp;i++)
    {
        cout<<sum.top();
        sum.pop();
    }
    cout<<"\n";
    return 0;
}
