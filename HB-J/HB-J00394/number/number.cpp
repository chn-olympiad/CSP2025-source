#include<bits/stdc++.h>
using namespace std;
int t,num[1000005];
bool cmp(int n,int m)
{
    return n > m;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int l = s.size();
    for(int i = 0;i < l;i++)
        if(s[i] >= '0' && s[i] <= '9')
            num[++t] = s[i] - '0';
    sort(num+1,num+t+1,cmp);
    for(int i = 1;i <= t;i++)cout << num[i];
    return 0;
}
