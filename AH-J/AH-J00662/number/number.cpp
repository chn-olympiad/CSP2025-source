#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll nums[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    for(int i=0;i<str.length();++i)
        if(str[i]>='0'&&str[i]<='9')
            nums[str[i]-'0']+=1;
    if(nums[9]==0&&nums[8]==0&&nums[7]==0&&nums[6]==0&&nums[5]==0&&nums[4]==0&&nums[3]==0&&nums[2]==0&&nums[1]==0)
        cout << 0;
    else
    {
        for(int i=9;i>=0;--i)
        {
            while(nums[i]--)cout << i;
        }
    }
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
