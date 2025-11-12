#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string s1[200005],s2[200005],a1[200005],a2[200005];
//int d1[200005],d2[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    int sum = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> s1[i] >> s2[i];
    }
    for(int i = 1;i <= q;i++)
    {
        cin >> a1[i] >> a2[i];
        sum = 0;
        if(a1[i].length() != a2[i].length())
        {
            cout << sum << endl;
            continue;
        }
        string sc = a1[i];
        for(int j = 0;j <= a1[i].length() - 1;j++)
        {
            string s3 = "";
            string s4 = "";
            for(int k = j;k <= a1[i].length() - 1;k++)
            {
                s3 += a1[i][k];
                //cout << s3 << endl;
                for(int m = 1;m <= n;m++)
                {
                    if(s3 == s1[m])
                    {
                        //cout << "yes" << endl;
                        sc = a1[i];
                        int js = 0;
                        for(int y = j;y <= k;y++)
                        {
                            sc[y] = s2[m][js];
                            js++;
                            //cout << sc << endl;
                        }
                        //cout << sc << endl;
                        if(sc == a2[i])
                        {
                            sum++;
                        }
                    }
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
