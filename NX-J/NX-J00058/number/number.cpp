#include <bits/stdc++.h>
using namespace std;
long long num[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long cnt=0;
    string s;
    cin>>s;
    for(long long i=0;i<s.size();i++)
    {
        if(int(s[i])==48||int(s[i])==49||int(s[i])==50||int(s[i])==51||int(s[i])==52||int(s[i])==53||int(s[i])==54||int(s[i])==55||int(s[i])==56||int(s[i])==57)
        {
            num[cnt]=s[i];
            cnt++;
        }
    }
    sort(num,num+cnt);
    for(int i=cnt-1;i>=0;i--)cout<<char(num[i]);
    return 0;
}
