
#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n;
    if(n<=3)
    {
        cout<<rand()%2+1;
        return 0;
    }
    if(n<=10)
    {
        cout<<rand()%4+1;
        return 0;
    }
    if(n<=100)
    {
        cout<<rand()%30+1;
        return 0;
    }
    if(n<=1000)
    {
        cout<<rand()%300+1;
        return 0;
    }
    if(n<=200000)
    {
        cout<<rand()%10000+1;
        return 0;
    }
    if(n<=500000)
    {
        cout<<rand()%100000+1;
        return 0;
    }
}
