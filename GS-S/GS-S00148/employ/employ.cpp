#include <bits/stdc++.h>
using namespace std;

string dif; // difficulty string
int n=0, m=0;
int P[501] = {}; // naixin
bool aFlag = false;
long long sum =0;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin>>n>>m;
    cin>>dif;// ( pow(n, n) / 998244353 )
    aFlag = dif.find('0') == -1;

    if (aFlag)
    {
        long long last=1;
        for (int i = 1; i <= n; i+=2)
        {
            if (i>n)
                {
                    for (int k = i-1; k <= n; k++)
                    {
                        last *= k;
                        last = last % 998244353;
                    }
            }else{
                last = (last * i * (i+1)) % 998244353;
            }
        }
        cout<<last % 998244353<<endl;
    }else{
        
    }
    
    return 0;
}

