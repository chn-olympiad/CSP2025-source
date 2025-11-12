#include<iostream>
#include<string>

using namespace std;
int nums[17];
string s;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<s.size();i++)
        if (s[i]>='0' && s[i]<='9')
            nums[s[i]-'0']++;
    for (int i=9;i>=0;i--)
        if (nums[i]>0)
            for (int j=1;j<=nums[i];j++)
                cout<<i;
    cout<<endl;
    return 0;
}
