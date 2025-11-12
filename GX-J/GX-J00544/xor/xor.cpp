#include <bits/stdc++.h>
using namespace std;

int ans = 0;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);


    int n, k;
    cin >> n >> k;
    vector<int> nums(n,0);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    if(count(nums.begin(), nums.end(), 1) + count(nums.begin(), nums.end(), 0) == n)
    {
        if(k==1)
        {
            ans += count(nums.begin(), nums.end(), 1);
        }
        else if(k==0)
        {
            for(int i = 0; i < n; i++)
            {
                if(i != n-1)
                {
                    if(nums[i] == 1 && nums[i+1] == 1)
                        ans++;
                }
                if(nums[i] == 0)
                    ans++;
            }
        }
    }
    else
    {
        //i cant do anything :(
    }

    cout << ans;

    return 0;
}
