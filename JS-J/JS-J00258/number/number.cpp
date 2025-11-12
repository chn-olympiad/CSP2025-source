#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    int s = a.size(),rp=0;
    for(int i = 0;i<s;i++)
    {
        if(a[i]>='0'&&a[i]<='9')nums.push_back(a[i]-'0'),rp++;
    }
    sort(nums.begin(),nums.begin()+rp);
    for(int i = rp-1;i>=0;i--)
    {
        cout << nums[i];
    }
    return 0;
}
//07:57 yi si bei CCF zuoju,shu biao you wen ti
//(yue)08:40 restart could solve 90% problem , started to read T1
//08:55 T1 ACed
//08:57 write the freopen
//freopen
//freopen
//freopen
