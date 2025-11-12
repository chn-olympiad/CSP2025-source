#include<bits/stdc++.h>
using namespace std;
int num[500005];
bool selected[500005];
int results[5002][5002];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt = 0;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++) cin >> num[i];
    for(int i = 0 ; i < n ; i++) results[i][i] =num[i];
    for(int i = 0 ; i < n ; i++)
    {
       for(int j = i+1 ; j < n ; j++)
       {

           results[i][j] = results[i][j-1] ^ num[j];
           //if (i == 2) cout << results[i][j] << endl;
       }
    } // no problem!
 //   cout << results[0][0] << " " << results[1][3] << endl;
    for(int l1 = 0 ; l1 < n ; l1++)
    {
        for(int r1 = l1 ; r1 < n ; r1++)
        {

    //                printf("%d %d , %d %d",l1,r1,l2,r2);
                    if(results[l1][r1] == k)
                    {
                        bool invalid= 0;
                        for(int i = l1 ; i <= r1 ; i++)
                        {
                            if (selected[i] == 1)
                            {
                                invalid=1;
                                break;
                            }
                            selected[i] = 1;
                        }
                        if (invalid) continue;
                            //cout << l1 << " " << r1 << endl;
                        cnt++;
                    }
            }
        }

    cout << cnt;
}
