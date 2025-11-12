#include<iostream>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int first_club;
    int second_club;
    int third_club;
    int n;
    int l[100];
    int t;
    cin >> t;
    for(int i = 0;i < t;i++)
    {
        int temp;
        cin >> temp;
        n += temp;
        int good_num;
        int every_max = n/2;
        for(int j = 0;j < temp;j++)
        {
            int a1,a2,a3;
            cin >> a1 >> a2 >> a3;
            if(a1>a2 && a1>a3)
            {
                if(first_club >= n/2)
                {
                    if(a2>a3)
                    {
                        second_club++;
                        good_num += a2;
                        continue;
                    }
                    else
                    {
                        third_club++;
                        good_num += a3;
                        continue;
                    }
                }
                first_club++;
                good_num += a1;
            }
            else if(a2>a2 && a2>a3)
            {
                if(second_club >= n/2)
                {
                    if(a1>a3)
                    {
                        first_club++;
                        good_num += a1;
                        continue;
                    }
                    else
                    {
                        third_club++;
                        good_num += a3;
                        continue;
                    }
                }
                second_club++;
                good_num += a2;
            }
            else if(a3>a2 && a3>a1)
            {
                if(third_club >= n/2)
                {
                    if(a1>a2)
                    {
                        first_club++;
                        good_num += a1;
                        continue;
                    }
                    else
                    {
                        second_club++;
                        good_num += a2;
                        continue;
                    }
                }
                first_club++;
                good_num += a1;
            }
        }
        l[i] = good_num;
    }
    for(int i = 0;i < t;i++)
    {
        if(l[i]!=0)    cout << l[i];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
