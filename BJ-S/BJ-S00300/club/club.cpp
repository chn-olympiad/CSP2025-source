#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long sum = 0;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int i = 1; i <= n; i++)
        {
            int max1 = max(one[i], max(two[i], three[i])), max2, max3;
            if (max1 == one[i])
            {
                max2  = max(two[i],three[i]);
                max3 = min(two[i],three[i]);
            }
            if (max1 == two[i])
            {
                max2  = max(one[i],three[i]);
                max3 = min(one[i],three[i]);
            }
            if (max1 == three[i])
            {
                max2  = max(one[i],two[i]);
                max3 = min(one[i],two[i]);
            }
            if ((max1 == one[i]))
            {
                if (cnt1 <= n / 2)
                {
                    sum += max1;
                    cnt1++;
                }
                else
                {
                    if (max2 == two[i])
                    {
                        if (cnt2 <= n / 2)
                        {
                            sum += max2;
                            cnt2++;
                        }
                        else
                        {
                            if (max3 == three[i])
                            {
                                if (cnt3 <= n / 2)
                                {
                                    sum += max3;
                                    cnt3++;
                                }
                            }
                        }
                    }
                    else if(max2 == three[i])
                    {
                        if (cnt3 <= n/ 2)
                        {
                            sum += max2;
                            cnt3++;
                        }
                        else
                        {
                            if (max3 == two[i])
                            {
                                if (cnt2 <= n / 2)
                                {
                                    sum += max3;
                                    cnt2++;
                                }
                            }
                        }
                    }
                }
            }
            else if ((max1 == three[i]))
            {
                if (cnt3 <= n / 2)
                {
                    sum += max1;
                    cnt3++;
                }
                else
                {
                    if (max2 == two[i])
                    {
                        if (cnt2 <= n / 2)
                        {
                            sum += max2;
                            cnt2++;
                        }
                        else
                        {
                            if (max3 == one[i])
                            {
                                if (cnt1 <= n / 2)
                                {
                                    sum += max3;
                                    cnt1++;
                                }
                            }
                        }
                    }
                    else if(max2 == one[i])
                    {
                        if (cnt1 <= n/ 2)
                        {
                            sum += max2;
                            cnt1++;
                        }
                        else
                        {
                            if (max3 == two[i])
                            {
                                if (cnt2 <= n / 2)
                                {
                                    sum += max3;
                                    cnt2++;
                                }
                            }
                        }
                    }
                }
            }
            else if ((max1 == two[i]))
            {
                if (cnt2 <= n / 2)
                {
                    sum += max1;
                    cnt2++;
                }
                else
                {
                    if (max2 == one[i])
                    {
                        if (cnt1 <= n / 2)
                        {
                            sum += max2;
                            cnt1++;
                        }
                        else
                        {
                            if (max3 == three[i])
                            {
                                if (cnt3 <= n / 2)
                                {
                                    sum += max3;
                                    cnt3++;
                                }
                            }
                        }
                    }
                    else if(max2 == three[i])
                    {
                        if (cnt3 <= n/ 2)
                        {
                            sum += max2;
                            cnt3++;
                        }
                        else
                        {
                            if (max3 == one[i])
                            {
                                if (cnt1 <= n / 2)
                                {
                                    sum += max3;
                                    cnt1++;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}