#include<bits/stdc++.h>;
using namespace std;
int n,i,j,a1=0,b1=0,c1=0,ans=0,sum=0,amin=INT_MAX,bmin=INT_MAX,cmin=INT_MAX;
int samin=9,sbmin=9,scmin=9;
int a[100000][2];
int xmin()
{
        //cout<<i<<endl;

        for(j=0;j<=i;j++)
        {

            if(a[i][0]<amin)
            {
                amin=a[i][0];
                samin=i;
            }
            if(a[i][1]<bmin)
            {
                bmin=a[i][1];
                sbmin=i;
            }
            if(a[i][2]<cmin)
            {
                cmin=a[i][2];
                scmin=i;
            }
        }

        if(a[i][0]>a[i][1] and a[i][0]>a[i][2])
        {
                return 0;
                //cout<<i<<" "<<"0 1 "<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl;
        }
            if(a[i][1]>a[i][0] and a[i][1]>a[i][2])
                return 1;
            else if(a[i][2]>a[i][1] and a[i][2]>a[i][0])
                return 2;
            else if(a[i][0]>a[i][1] and a[i][1]==a[i][2])
                return 0;
                //cout<<"0 2"<<endl;
            else if(a[i][0]>a[i][1] and a[i][0]==a[i][2])
            {
                if(a1>c1)
                    return 2;
                if(c1>a1)
                    return 0;
                    //cout<<"0 3"<<endl;
            }
            else if(a[i][2]>a[i][0] and a[i][0]==a[i][1])
                return 2;
            else if(a[i][2]>a[i][0] and a[i][1]==a[i][2])
            {
                if(b1>c1)
                    return 2;
                if(c1>b1)
                    return 1;
                    //cout<<"0 3"<<endl;
            }
            else if(a[i][1]>a[i][2] and a[i][0]==a[i][2])
                return 1;
            else if(a[i][1]>a[i][2] and a[i][1]==a[i][0])
            {
                if(a1>b1)
                    return 1;
                if(b1>a1)
                    return 0;
                    //cout<<"0 3"<<endl;
            }
                //cout<<"rsgrshfcgnv"<<endl;
                    //cout<<"0 4"<<endl;
        //cout<<amin<<" "<<bmin<<" "<<cmin<<" "<<endl;
}
int fun(int sum,int l)
{

    if(sum=0 and a1>=l)
    {

        if(a[i][0]<amin)
        {
            if(a[i][2]>a[i][1])
                return fun(2,l);
            if(a[i][1]>a[i][2])
                return fun(1,l);
        }
        else
        {
            ans-=amin;
            a1-=1;
            a[samin][0]=INT_MAX;
            xmin();
        }


    }
    if(sum=1 and b1>=l)
    {

        if(a[i][1]<bmin)
        {
            if(a[i][0]>a[i][2])
                return fun(0,l);
            if(a[i][2]>a[i][0])
                return fun(2,l);
        }
        else
        {
            ans-=bmin;
            b1-=1;
            a[sbmin][1]=INT_MAX;
            xmin();
        }
    }
    //cout<<sum<<endl;
    if(sum=2 and c1>=l)
    {

        if(a[i][2]<cmin)
        {
            if(a[i][0]>a[i][1])
                return fun(0,l);
            if(a[i][1]>a[i][0])
                return fun(1,l);
        }
        else
        {
            ans-=cmin;
            c1-=1;
            a[scmin][2]=INT_MAX;
            xmin();
        }
    }
    //cout<<sum<<endl;
    cout<<i<<" "<<sum<<" "<<a[i][sum]<<endl;

    return a[i][sum];
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,t1=0;
    cin>>t;
    int a_[100000];
    for(t1=0;t1<t;t1++)
    {
        ans=0;
        cin>>n;
        int l=n/2,s=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        for(i=0;i<n;i++)
        {
            if(a[i][1]!=0 and a[i][2]!=0)
                break;
            else
                s++;
        }
        if(s>=n-1)
        {
            for(i=0;i<n;i++)
                a_[i]=a[i][0];
            sort(a_,a_+n);
            for(i=-1;i>=-l;i--)
                ans+=a_[i];
            cout<<ans;
            return 0;
        }
        for(i=0;i<n;i++)
        {
            //cout<<xmin()<<endl;
            sum=xmin();
            ans+=fun(sum,l);
            if(sum==0)
                a1++;
            if(sum==1)
                b1++;
            if(sum==2)
                c1++;
        }
        cout<<ans<<endl;
    }
}
