#include<bits/stdc++.h>
using namespace std;

string s;

vector<int> num;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
            num.push_back(0);
        else if(s[i]=='1')
            num.push_back(1);
        else if(s[i]=='2')
            num.push_back(2);
        else if(s[i]=='3')
            num.push_back(3);
        else if(s[i]=='4')
            num.push_back(4);
        else if(s[i]=='5')
            num.push_back(5);
        else if(s[i]=='6')
            num.push_back(6);
        else if(s[i]=='7')
            num.push_back(7);
        else if(s[i]=='8')
            num.push_back(8);
        else if(s[i]=='9')
            num.push_back(9);
    }
    sort(num.begin(),num.end(),cmp);
    for(int i=0;i<num.size();i++)
        cout<<num[i];
    return 0;
}
