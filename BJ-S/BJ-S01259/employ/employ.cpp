#include <bits/stdc++.h>
using namespace.std
int main()
{
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
string st;
int n,m,nx[505]={},q=0,p=0;
long long au=1;
cin>>n>>m;
cin>>st;
for(inti=1;i<=n;i++){
    cin>>nx[i];
}
for(int i=1;i<=n;i++)
{
    au*=i;
}
for(long long k=1;k<=au;k++)
{
    for(int i=1;i<=n;i++)
    {
        if(st[i-1]=='1')
        {
            if(nx[i]>0)
            {
                    q++;
            }
            else
            {
                 for(int j=i+1;j<=n;j++)
                 {
                     nx[j]--;
                 } 
            }
        }
        else{
            for(int j=i+1;j<=n;j++)
            {
                nx[j]--;
            }
        }
        if(q>=m)
        {
            p++;
        }
    }
}
fclose(stdin);
fclose(stdout);
    return 0;
}