#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int z,o;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int ci;
        cin>>ci;
        if(ci==0){z++;}
        if(ci==1){o++;}
        a.push_back(ci);
    }
    if(n==1){cout<<0;return 0;}
    if(k==0){cout<<z;}
    if(k==1){
        cout<<min(o,z);
    }

    return 0;
}
