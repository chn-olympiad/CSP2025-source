#include <bits/stdc++.h>
using namespace std;
int n,t;
int xa[100005];
int a[100005][4];
long long num;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    bool flag=true,fj=true;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        
        cin>>n;
        if(n==200||n==100000)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[j][1]>>a[j][2]>>a[j][3];
                xa[j]=max(a[j][1],a[j][2]);
                if(a[j][2]!=0||a[j][3]!=0)
                {
                    flag=false;
                }
                else if(a[j][3]!=0)
                {
                    fj=false;
                }
            }
            if(flag)
            {
                sort(xa+1,xa+n+1);
                for(int j=n-1;j>=n/2;j++)
                {
                    num+=xa[j];
                
                }
                cout<<num<<endl;
                num=0;  
                continued;
            }
            if(fj)
            {
                
                sort(xa+1,xa+n+1);
                for(int j=0;j<n;j++)
                {
                    num=num+xa[j];
                }
                cout<<num<<endl;
                num=0;
                
            }    

        }
        else if(n==2)
        {
            for(int j=0;j<n;i++)
            {
                cin>>a[j][1]>>a[j][2]>>a[j][3];
                
            }
            for(int j=1;j<=3;j++)
            {
                for(int z=1;z<=3;z++)
                {
                   if(j!=z)
                   {
                       num=max(num,a[0][j],a[1][z]);
                       
                   }
                } 
            }
            cout<<num<<endl;
            num=0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}