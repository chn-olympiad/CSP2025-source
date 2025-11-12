#include <bits/stdc++.h>

using namespace std;
string s;
vector<int> a;
long long a_size,arr[100010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin >> s;
    for(int i = 0;i < s.size();i ++)
    {
        if(s[i] - '0'>= 0 &&s[i] - '0' <= 9)
        {
            a.push_back(s[i] - '0');
            a_size ++;
        }

    }
    for(int i = 0;i < a_size;i ++)
    {
        arr[i] = a[i];
    }


    sort(arr,arr + a_size,greater<int>());
    for(int i = 0;i < a_size;i ++)
    {
        printf("%lld",arr[i]);
    }
    return 0;
}



