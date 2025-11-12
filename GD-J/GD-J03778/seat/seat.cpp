#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int a[105];
int hang,lie;
int main()
{

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,mark,num;
    cin>>n>>m;
    cin>>mark;
    a[1]=mark;
    for(int i = 2;i<=n*m;i++)
    {
        cin>>a[i];

    }

    sort(a+1,a+n*m+1);
    for(int i = 1;i<=n*m;i++)
    {
        if(a[i]==mark)
        {
            num=m*n-i+1;
        }


    }
    lie=num/n;
    if(num%n>0)
    {
        lie++;

    }
    if(lie%2==0)
    {
        hang=n-num%n+1;
    }
    else
    {
        hang=num%n;
    }
    if(hang==0)
    {
        if(lie%2==0)
        {
        hang=1;
        }
        else
        {
            hang=n;
        }
    }
    cout<<lie<<" "<<hang;




}

