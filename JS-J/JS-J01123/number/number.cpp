#include<bits/stdc++.h>
using namespace std;
long long bucket[15];
int main()
{
    freopen("number.in","r",stdin);freopen("number.out","w",stdout);
    memset(bucket,0,sizeof(bucket));
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            bucket[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        while(bucket[i]!=0){
            cout<<i;
            bucket[i]--;
        }
    }
    return 0;
}
