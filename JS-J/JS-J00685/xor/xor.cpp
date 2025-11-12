#include<bits/stdc++.h>
using namespace std;

int a[500015], b[500015];


int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n, k, tt = 0, jsq = 0, tttt=0;
    cin >> n>> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    b[0] = 0;
    for(int i = 1; i <= n; i++)
        b[i] = (b[i - 1] ^ a[i]);
    for(int i = 1; i <= n; i++)
    {
        for(int j = tt; j < i; j++)
            {
                if((b[i] ^ b[j]) == k)
                {
                    jsq++;
                    tttt = i;
                    j = i + 1;
                }
            }
        tt = tttt;
    }
    cout << jsq<< endl;
}
