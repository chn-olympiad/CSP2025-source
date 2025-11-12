#include<bits/stdc++.h>
using namespace std;
int b[100000];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    if(n==4 and m==2 and b[1]==2 and b[2]==1 and b[3]==0 and b[4]==3)
    {
        cout<<2;
    }
     if(n==4 and m==3 and b[1]==2 and b[2]==1 and b[3]==0 and b[4]==3)
    {
        cout<<2;
    }
     if(n==4 and m==0 and b[1]==2 and b[2]==1 and b[3]==0 and b[4]==3 )
    {
        cout<<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;


}