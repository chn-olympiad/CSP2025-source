#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    vector<int> num;
    char ch;
    int cnt=0;
    while(cin>>ch)
    {
        if(ch>='0'&&ch<='9')
        {
            num.push_back(ch-'0');
            cnt++;
        }
    }
    sort(num.begin(),num.end());
    for(int i=cnt-1;i>=0;i--)
    {
        cout<<num[i];
    }
    return 0;
}
