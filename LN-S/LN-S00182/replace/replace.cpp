#include<bits/stdc++.h>
using namespace std;
mt19937 gen(time(0)^random_device()());
uniform_int_distribution<int> dist(1,100);
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    cout<<dist(gen)<<endl;
    }
    return 0;
}
