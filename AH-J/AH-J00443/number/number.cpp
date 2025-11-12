#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char n[1000001];
    long long a[1000001];
    for(int i=1;i<=100;i++)
    {
        cin>>n[i];
        a[i]=n[i];
    }
    long long s=0;
    for(int i=1;i<=100;i++)
    {
        if(a[i]<=9)
            s++;
        else
        {
            for(int j=i;j<=100;j++)
                a[j]==a[j+1];
        }
    }
    bool t[s+1];
    for(int i=1;i<=s;i++)
        t[i]=true;
    for(int j=1;j<=s;j++)
    {
        int max=a[j];
        for(int i=2;i<=s;i++)
        {
            if(a[i]>max&&t[i])
                max=a[i];
        }
        for(int i=1;i<=s;i++)
        {
            if(a[i]==max)
            {
                t[i]=false;
                break;
            }
        }
        if(max==0)
        {
            cout<<"0"<<endl;
            return 0;
        }
    }
        cout<<max-48<<endl;
    return 0;
}
