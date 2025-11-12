#include<bits/stdc++.h>
using namespace std;
string s;
int nums[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++) 
        if('0'<=s[i]&&s[i]<='9') nums[s[i]-'0']++;
    bool flag=0;
    for(int i=9;i>=0;i--)
    {
        while(nums[i])
        {
            if(i!=0) flag=1;
            else if(flag==0)
            {
                cout<<0;
                break;
            }
            cout<<i;
            nums[i]--;
        }
    }
    cout<<endl;
    return 0;
}