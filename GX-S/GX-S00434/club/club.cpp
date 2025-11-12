#include <bits/stdc++.h>
using namespace std;

long long t,n,a[200090][4]= {0},ma=0,z[1000000],sum=0,a1=0,a2=0,a3=0,ma1=0,p1=0,j11=0;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>n;
        ma=n/2;
        for(int j=0; j<n; j++)
        {
            scanf("%lld %lld %lld",&a[j][0],&a[j][1],&a[j][2]);
        }
        for(int q=0; q<n; q++)
        {
            ma1=0;
            for(int j=0; j<n; j++)
            {
                for(int p=0; p<3; p++)
                {
                    if(p==0)
                    {
                        if(a1<ma&&ma1<a[j][p])
                        {
                            ma1=max(ma1,a[j][p]);
                            p1=p;
                            j11=j;
                            //cout<<"PPP1"<<endl;
                        }
                    }
                    else if (p==1&&ma1<a[j][p])
                    {
                        if(a2<ma)
                        {
                            ma1=max(ma1,a[j][p]);
                            p1=p;
                            j11=j;
                            //cout<<"PPP2"<<endl;
                        }
                    }
                    else if(p==2&&ma1<a[j][p])
                    {
                        if(a3<ma)
                        {
                            ma1=max(ma1,a[j][p]);
                            p1=p;
                            j11=j;
                            //cout<<"PPP3"<<endl;
                        }
                    }
                }
            }
            if(p1==0){
                a1++;
            }else if(p1==1){
                a2++;
            }else{
                a3++;
            }
            sum+=ma1;
            a[j11][p1]=0;
            //cout<<sum<<" "<<j11<<" "<<p1<<endl;
            //for(int j=0; j<n; j++)
            //{
                //for(int p=0; p<3; p++){
                //    cout<<a[j][p];
                //}
                //cout<<endl;
            //}
        }

        cout<<sum<<endl;
        sum=0;
        a1=0;
        a2=0;
        a3=0;
        ma1=0;
    }
    return 0;
}
