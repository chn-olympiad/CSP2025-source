#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    freopen("club.in","r",std)
    freopen("club.out","w",std)
    int t=0;
    cin>>t;
    for(int term=0;term<t;term++)
    {
        int num=0,sum=0;
        cin>>num;
        int a1[num]={0},a2[num]={0},a3[num]={0};
        int b[num]={0};
        for(int f=0;f<num;f++)
        {
            cin>>a1[f]>>a2[f]>>a3[f];
            int maxn[f]=max{a1[f],a2[f],a3[f]};
            sum+=max[f]
        }
        cout<<sum<<endl;


    }
    return 0;
}
