#include<bits/stdc++.h>
using namespace std;
int arr[100009][4]={0};
int n;
int ans=0;
short v[4]={0};
void fun(int a,int b)
{
    if(a>n)
    {
        ans=max(ans,b);
        return ;
    }
    for(int i=1;i<=3;i++)
    {
        if(v[i]<(n/2))
        {
            v[i]++;
            fun(a+1,b+arr[a][i]);
            v[i]--;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
            cin>>arr[j][1]>>arr[j][2]>>arr[j][3];
        ans=0;
        v[1]=v[2]=v[3]=0;
        fun(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
