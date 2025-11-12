#include<iostream>
#include<string>
#include<fstream>
#include<queue>
using namespace std;
priority_queue<int> qk;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        int temp=0;
        if(s[i]>='0'&&s[i]<='9')
        {
            temp=int(s[i]-'0');
            qk.push(temp);
        }
    }
    while(!qk.empty())
    {
        int cf=qk.top();
        cout<<cf;
        qk.pop();
    }
    return 0;
}
