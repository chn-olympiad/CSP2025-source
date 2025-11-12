#include<bits/stdc++.h>
using namespace std;
long long S1[1000005]={};
long long S2[100];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T1=0;
    long long N1=0,Sum1=0,N2=0;
    cin>>T1;
    for(int i=0;i<T1;i++)
    {
        cin>>N1;
        for(int j=0;j<N1*3;j++)
        {
            cin>>S1[j];
        }
        for(int k=0;k<N1*3;k+=3)
        {
            Sum1=0;

            Sum1=max(Sum1,max(max(S1[k],S1[k+1]),S1[k+2]));
            N2+=Sum1;
            S2[i]=N2;
        }
        N2=0;
    }

    for(int i=0;i<T1;i++)
    {
        cout<<S2[i]<<endl;
    }
    return 0;
}
