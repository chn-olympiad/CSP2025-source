#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],i,j,x,s=1;
bool b=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    x=a[1];
    for(i=2;i<=n*m;i++)
    {
        cin>>a[i];
        for(j=i;j>1;j--)
                if(a[j]>a[j-1])
                    swap(a[j],a[j-1]);
    }
    i=1;
    while(a[i]!=x)i++;
    if(i%n!=0)cout<<(i/n+1)<<" ";
    else cout<<(i/n)<<" ";
    for(j=1;j<=i-1;j++)
    {
        if(b)
            if(s<n)s++;
            else b=!b;
        else
            if(s>1)s--;
            else b=!b;
    }
    cout<<s;
    return 0;
}
