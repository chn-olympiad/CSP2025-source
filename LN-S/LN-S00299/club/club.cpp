#include <bits/stdc++.h>
using namespace std;
long long T,n,a[100010],b[100010],c[100010],as=0,bn=0,cv=0,p=0;
int mm3(int a,int b,int c)
{
    if(a>=b&&a>=c)
    {
        return 1;
    }
    else if(b>=a&&b>=c)
    {
        return 2;
    }
    else if(c>=b&&c>=a)
    {
        return 3;
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int club=1;club<=T;club++)
    {
        p=0;as=0;bn=0;cv=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        sort(a+1,a+1+n);
        reverse(a+1,a+1+n);
        sort(b+1,b+1+n);
        reverse(b+1,b+1+n);
        sort(c+1,c+1+n);
        reverse(c+1,c+1+n);
        for(int i=1;i<=n;i++)
        {
            if(mm3(a[i],b[i],c[i])==1)
                {
                    if(as<n/2)
                    {
                        p+=a[i];
                        as++;
                    }
                    else
                    {
                        if(max(b[i],c[i])==b[i])
                        {
                            p+=b[i];
                            bn++;
                        }
                        else
                        {
                            p+=c[i];
                            cv++;
                        }

                    }
                }
                else if(mm3(a[i],b[i],c[i])==2)
                {
                    if(bn<n/2)
                    {
                        p+=b[i];
                        bn++;
                    }
                    else
                    {
                        if(max(a[i],c[i])==a[i])
                        {
                            p+=a[i];
                            as++;
                        }
                        else
                        {
                            p+=c[i];
                            cv++;
                        }
                    }
                }
                else if(mm3(a[i],b[i],c[i])==3)
                {
                    if(cv<n/2)
                    {
                        p+=c[i];
                        cv++;
                    }
                    else
                    {
                        if(max(a[i],b[i])==a[i])
                        {
                                p+=a[i];
                                as++;
                        }
                        else
                        {
                            p+=b[i];
                            bn++;
                        }
                    }
                }
        }
        cout<<p<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
