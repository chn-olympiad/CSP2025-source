#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[(int)1e5 + 10][4];
int f[(int)1e5 + 10][4];
int maxa[(int)1e5 + 10];
int maxf[(int)1e5 + 10];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t --)
    {

        int n;
        cin >> n;
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= 3; j ++)
            {
                cin >> a[i][j];
                maxa[i] = max(maxa[i], a[i][j]);
            }
        }
        // f[n][m] daibiaole n gerenzhong di n ge ren xuanze di m bumenshi de
        // zuida manyizhi
        f[2][1] = a[2][1] + max(a[1][2], a[1][3]);
        f[2][2] = a[2][2] + max(a[1][1], a[1][3]);
        f[2][3] = a[2][3] + max(a[1][1], a[1][2]);
        maxf[2] = *max_element(f[2] + 1, f[2] + 4);

        /*f[3][1][1] = a[3][1] + a[2][1] + max(a[1][2], a[1][3]);
        f[3][1][2] = a[3][1] + a[2][2] + *max_element(a[1] + 1, a[1] + 4);
        f[3][1][3] = a[3][1] + a[2][3] + *max_element(a[1] + 1, a[1] + 4);
        max f[3][1] = max(a[3][1] + f[2][1], a[3][1] + max a[1] + max(a[2][2], a[2][3]))

        f[3][2][1] = a[3][2] + a[2][1] + *max_element(a[1] + 1, a[1] + 4);
        f[3][2][2] = a[3][2] + a[2][2] + max(a[1][1], a[1][3]);
        f[3][2][3] = a[3][2] + a[2][3] + *max_element(a[1] + 1, a[1] + 4);
        max f[3][2] = max(a[3][2] + f[2][2], a[3][2] + max a[1] + max(a[2][1], a[2][3]))

        f[3][3][1] = a[3][3] + a[2][1] + *max_element(a[1] + 1, a[1] + 4);
        f[3][3][2] = a[3][3] + a[2][2] + *max_element(a[1] + 1, a[1] + 4);
        f[3][3][3] = a[3][3] + a[2][3] + max(a[1][1], a[1][2]);
        max f[3][3] = max(a[3][3] + f[2][3], a[3][3] + max a[1] + max(f[2][1], a[2][2]))*/


        /*f[4][1][1][1] =
        f[4][1][1][2] = a[4][1] + a[3][1] + a[2][2] + max(a[1][2], a[1][3]);
        f[4][1][1][3] = a[4][1] + a[3][1] + a[2][3] + max(a[1][2], a[1][3]);

        f[4][1][2][1] = a[4][1] + a[3][2] + a[2][1] + max(a[1][2], a[1][3]);
        f[4][1][2][2] = a[4][1] + a[3][2] + a[2][2] + max(a[1][1], a[1][3]);
        f[4][1][2][3] = a[4][1] + a[3][2] + a[2][3] + *max_element(a[1] + 1, a[1] + 4);

        f[4][1][3][1] = a[4][1] + a[3][3] + a[2][1] + max(a[1][2], a[1][3]);
        f[4][1][3][2] = a[4][1] + a[3][3] + a[2][2] + *max_element(a[1] + 1, a[1] + 4);
        f[4][1][3][3] = a[4][1] + a[3][3] + a[2][3] + max(a[1][1], a[1][2]);\

        f[4][2][2][1] = a[4][2] + a[3][2] + a[2][1] + max a[1]
        --f[4][2][2][2] = a[4][2] + a[3][2] + a[2][2] + max a[1]
        f[4][2][2][3] = a[4][2] + a[3][2] + a[2][3] + max a[1]


        --max f[4][1][1] = a[4][1] + a[3][1] + max(f[2][2], f[2][3])
        max f[4][1][2] = a[4][1] + a[3][2] + max(max(f[2][1], f[2][2]), max a[1])
        max f[4][1][3] = a[4][1] + a[3][3] + max(max(f[2][1], f[2][3]), max a[1])
        max f[4][2][1] = a[4][2] + a[3][1] + max(max(f[2][2], f[2][1]), max a[1])
        max f[4][2][3] = a[4][2] + a[3][3] + max(max(f[2][2], f[2][3]), max a[1])
        max(max(a,b), max(a,c), max(b,c))
        max(max(a,b), max(a,c))
                                                // max(max f[2], max f[1])
        //max f[4][1] = a[4][1] + max a[3] + max({max(f[2][2], f[2][3]), max(max(f[2][1], f[2][2]), max a[1]), max(max(f[2][1], f[2][3]), max a[1])})
        --max f[4][1] = a[4][1] + max(a[3][2], a[3][3]) + max(max f[2], max a[1])
        max f[4][1] = a[4][1] + max(a[3][2] + max(max(f[2][1], f[2][2]), max a[1]),
                                    a[3][3] + max(max(f[2][1], f[2][3]), max a[1]))

        max f[4][2] = a[4][2] + max(a[3][ + max(max f[2], max f[1])
        max f[4][3] = a[4][3] + max a[3] + max(max f[2], max f[1])*/

        //max f[4] = max a[4] + max a[3] + max(max f[2], max a[1])

        int max1, max2, max3;
        for(int i = 4; i <= n; i += 2)
        {
            //cout << i << "---" <<endl;
            //cout << i << "---" <<endl;
            max1 = a[i][1] + max(a[i - 1][2] + max(max(f[i - 2][1], f[i - 2][2]), maxa[i - 3]),
                                 a[i - 1][3] + max(max(f[i - 2][1], f[i - 2][3]), maxa[i - 3]));
            max2 = a[i][2] + max(a[i - 1][1] + max(max(f[i - 2][2], f[i - 2][1]), maxa[i - 3]),
                                 a[i - 1][3] + max(max(f[i - 2][2], f[i - 2][3]), maxa[i - 3]));
            max3 = a[i][3] + max(a[i - 1][1] + max(max(f[i - 2][3], f[i - 2][1]), maxa[i - 3]),
                                 a[i - 1][2] + max(max(f[i - 2][3], f[i - 2][2]), maxa[i - 3]));
            //cout << "max11: "<< a[i - 1][2] + max(max(f[i - 2][1], f[i - 2][2]), maxa[i - 3] << endl;
            //cout << "max12: "<< a[i - 1][3] + max(max(f[i - 2][1], f[i - 2][3]), maxa[i - 3]) << endl;
            //cout << "max3: "<< max3 << endl;
            maxf[i] = max({max1, max2, max3}) + 1;

        }

        //for(int i = 1; i <=n ;i ++)
        //    cout <<"A max: "<< maxa[i]<< endl;

        cout << maxf[n] << endl;
        memset(maxa, 0, sizeof(maxa));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
