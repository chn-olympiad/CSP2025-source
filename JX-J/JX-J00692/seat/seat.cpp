#include<bits/stdc++.h>
using namespace std;
int a[105];
int s[105];
int t=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1)
        {
            t=a[i];
        }
        int w=a[i];
        s[w]=1;
    }
    int pm=1;
    for(int i=100;i>t;i--)
    {
        if(s[i]==1)
        {
            pm+=1;
        }
    }
    int le,hang;
    le=(pm-1)/m+1;
    if(pm%n==0)hang=m;
    else hang=pm%n;
    cout<<le<<" "<<hang;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
