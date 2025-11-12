#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string s;
int a[1000005];
int main()
{

    cin >>s;
    long long j=0;
    for(int i=0;i<s.size();i++)
    {
    if(int(s[i])==49||int(s[i])==50||int(s[i])==51||int(s[i])==52||int(s[i])==53||int(s[i])==54||int(s[i])==55||int(s[i])==56||int(s[i])==57||s[i]=='0')
    {
        j++;
        a[j]=s[i];

    }
    }
    sort(a-1,a+j);
    for(int i=j;i>=1;i--)
    {
        cout << a[i]-48;}

    return 0;
}
