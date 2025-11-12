#include<bits/stdc++.h>
using namespace std;
string s;
int a[10010],c,sum=0;
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    //1,a5b1     1   5
    // 2.      15<51
    //cout 52;
    cin>>s;
    int k=0,i=0;
    while(1)
    {
        c=int(s[i]);
        if(c>0)
        {
            sum++;
        }
        else{
            break;
        }
        i++;
    }
   for(int i=0;i<=sum;i++)
    {
        if(s[i]>=48&&s[i]<=56)
        {
            cout<<type(s[i]);
            a[k]=int(s[i]);
            cout<<a[k]<<" ";
            k++;        }

    }

    for(int i=1;i<=k;i++)
    {
        cout<<a[i]<<" ";
    }/*
    int d=0,pp,qq;;
    cout<<"____________";
    for(int i=1;i<=k;i++)
    {
        if(a[i]<a[i+1])
        {
            pp=a[i+1];
            a[i+1]=a[i];
            qq=a[i];
        }
    }
    for(int i=1;i<=k;i++)
    {
        cout<<"1 ";
        cout<<a[i];
        cout<<"* ";
    }

    /*for(int i=1;i<=k;i
    ++)
    {
        cout<<a[i]<<"########";
    }*/
}
