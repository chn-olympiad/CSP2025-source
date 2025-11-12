#include <bits/stdc++.h>
using namespace std;
bool b[100][3];bool c[1000]={0};bool d={1001};
int max1=0;
int print(int num)
{
    cout<<num<<" ";
    max1=max(max1,num);
}
int search(int a,int i);
{
    for(int o=0;o<3;o++)
    {
        if(!b[j][o] && !c[i] && !d[o]<n)
            {
                b[i][j]=1;
                c[i]=1;
                d[j]++;
                num+=a[i][j];
                if(i=2*n)print(num);
                else search(a,i+1,n,num);
                num-=a[i][j];
                d[j]--;
                b[i][j]=0;
                c[i]=0;
            }
    }
}
int main()
{
    freopen("clud.in","r",stdin);
    freopen("clud.out","w",stdout);
    int t;
    for(int i=0;i<=t;i++)
    {
        int n;
        cin>>n;
        int a[n][3];
        for(int j=0;j<n;j++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][3];
        }
        search(a,0,a/2,0);
        m[o]=max1;
        for(int i=0;i<t;i++)
        {
            
            cout<<m[i]<<endl;
            
        }
    }
    cout<<m[t-1];
    return 0;
}
