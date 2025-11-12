#include<bits/stdc++.h>
using namespace std;
mt19937 gen(time(0)^random_device()());
uniform_int_distribution<int> dist(1,100);
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cout<<dist(gen);
    return 0;
}
