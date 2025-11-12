#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int r=a[0];
    if(n==1&&m==1)
    {
        cout<<"1 1"<<endl;
        return 0;
    }
    if(n==1)
    {
        for(int i=0;i<m-1;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                if(a[i]<a[j])
                {
                    int t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            if(a[i]==r)
            {
                cout<<"1 "<<i+1<<endl;
                return 0;
            }
        }
    }
    if(m==1)
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]<a[j])
                {
                    int t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]==r)
            {
                cout<<i+1<<" 1"<<endl;
                return 0;
            }
        }
    }
    return 0;
}