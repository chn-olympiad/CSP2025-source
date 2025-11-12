#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
long long n,m,s,d,f,t,a[100000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(s=0;s<n*m;s++)
     cin>>a[s];
    d=a[0];
    sort(a,n*m+a,cmp);
    for(s=0;s<n*m;s++)
    {
        if(a[s]==d)
        {
            cout<<s/m+1<<" ";
            if(s/m%2==0)
             cout<<s%m+1;
            else
             cout<<m-s%m;
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
