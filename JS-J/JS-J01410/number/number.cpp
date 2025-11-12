#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int num[1000010]={};
    int i = 1;
    for(int j = 0 ; j < s.size();j++)
    {
        if(s[j]>='0'&&s[j]<='9')
        {
            num[i]=s[j]-48;
            i++;
        }
    }

    i--;
    sort(num+1,num+1+i);
    for(int j = i ; j >= 1; j--)
    {
        cout << num[j];
    }
    return 0;
}
