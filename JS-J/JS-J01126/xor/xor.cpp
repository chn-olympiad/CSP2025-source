#include <bits/stdc++.h>
using namespace std;
int n;
/*
struct xxx{

};
xxx ecm[DATA]={};
*/
/*
xx P()
{
    return xx;
}
*/
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int k=0;
    scanf("%d%d",&n,&k);
    int data[2];
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }
    int ecp=0,res=0;
    for(int i=0;i<n;i++)
    {
        ecp^=data[i];
        if(ecp==0)
        {
            res++;
        }
    }
    cout<<res;
    return 0;
}