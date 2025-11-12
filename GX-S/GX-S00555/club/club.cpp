#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
cin>>t;
int n[6];
int a[100001],b[100001],c[100001],A=0,B=0,C=0;
int dl=0;
long long s=0,mx=0,k=0;
for(int i=1;i<=t;i++)
{
    cin>>n[i];
    dl=n[i]/2;
    for(int j=1;j<=n[i];j++)
    {
        cin>>a[j]>>b[j]>>c[j];
    }
    for(int p=1;p<=3;p++)
    {
        s=0;
        for(int j=1;j<=n[i];j++)
        {
            s+=max(max(a[j],b[j]),c[j]);
            if(max(max(a[j],b[j]),c[j])==a[j])
            {
                A++;
            }
            if(max(max(a[j],b[j]),c[j])==b[j])
            {
                B++;
            }
            if(max(max(a[j],b[j]),c[j])==c[j])
            {
                C++;
            }
            if(s>mx && A<=dl && B<=dl && C<=dl)
            {
                mx=s;
            }
            else
            {
                if(A>dl)
                {
                    A--;
                    s-=max(max(a[j],b[j]),c[j]);
                    s+=max(b[j],c[j]);
                    if(max(b[j],c[j])==b[j])
                    {
                        b[j]=0;
                        B++;
                    }
                    else
                    {
                        c[j]=0;
                        C++;
                    }

                }
                if(B>dl)
                {
                    B--;
                    s-=max(max(a[j],b[j]),c[j]);
                    s+=max(a[j],c[j]);

                        if(max(a[j],c[j])==a[j])
                        {
                            a[j]=0;
                            A++;
                        }
                        else
                        {
                            c[j]=0;
                            C++;
                        }

                }
                if(C>dl)
                {
                    C--;
                    s-=max(max(a[j],b[j]),c[j]);
                    s+=max(a[j],b[j]);

                        if(max(a[j],b[j])==a[j])
                        {
                            a[j]=0;
                            A++;
                        }
                        else
                        {
                           b[j]=0;
                           B++;
                        }

                }
            }
            if(s>k && A<=dl && B<=dl && C<=dl) k=s;
            if(max(max(a[j],b[j]),c[j])==a[j]) a[j]=0;
            if(max(max(a[j],b[j]),c[j])==b[j]) b[j]=0;
            if(max(max(a[j],b[j]),c[j])==c[j]) c[j]=0;
        }
    }
    cout<<k<<endl;
}
return 0;
}



