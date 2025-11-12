#include <bits/stdc++.h>

using namespace std;

struct du
{
    
    int a1,a2,a3;
}e[10088];
const int N=1e5+10;
int b11[N][3];
int aa,bb,cc;
int main()
{int t,n;
    int chu1,chu2,chu3;
    int guo=0;
    int guo2=0;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
    
        for(int j=1;j<=n;j++)
        {
            
            cin>>e[j].a1>>e[j].a2>>e[j].a3;	
            b11[j][0]=e[j].a1;
            b11[j][1]=e[j].a2;
            b11[j][2]=e[j].a3;
        }

        if(n==2)
        {
            chu1=max((e[1].a1+e[2].a2),(e[1].a1+e[2].a3));
            chu2=max((e[1].a2+e[2].a1),(e[1].a2+e[2].a3));
            chu3=max((e[1].a3+e[2].a1),(e[1].a3+e[2].a2));
            guo+=max(chu1,chu2);
            guo2+=max(guo,chu3);
            cout<<guo2;
    }
}
    return 0;
}
