#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("polygon","r",stdin)
    //freopen("polygon","w",stdout)
    long long  n = 0;
    cin>>n;
    long long a[n] = {};
    cin>>a[n];
    long long b = 0;
    for(long long i = 0;i <= n;i++)
    {
        if(n >= 3)
        {
            n -= '1';
            if(n = '0')
            {
                b += 1;
            }
        }
    }
    cout<<b<<endl;
}
