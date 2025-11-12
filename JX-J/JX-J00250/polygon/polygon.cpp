#include <bits/stdc++.h>
using namespace std;
int n,a[100005];
int sum;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i <=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=3;i <=n;i++)
    {
        int l = 1,r = 2,e = 3;
        if(i ==3)
        {
           while(l <=r && r <=n && e <=n)
            {
                while(a[l] + a[r] + a[e] >= 2*a[e])
                    {
                    sum++;
                    e++;
                }
                r++;
                e = r+1;
                if(r == n)
                {
                    l++;
                    r = l+1;
                }
            }
        }
        if(i ==4)
        {
            int z =3;
            e =4;
            while(a[l]+a[r]+a[z]+a[e] >= 2*a[e])
            {
                sum++;
                e++;
            }
            z++;
            e=z+1;
            r++;
            if(r==n)
            {
                l++;
                r = l+1;
            }
        } 
    }
        
    cout <<sum;
    return 0;
}
