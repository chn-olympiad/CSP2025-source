#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
int siz=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            int a=s[i]-'0';
            q.push(a),siz++;
        }
    }
    for(int i=0;i<siz;i++)
    {
        cout<<q.top();
        q.pop();
    }
    cout<<endl;
    return 0;
}
