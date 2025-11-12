#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],s,k,seat;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[++k];
    }
    s=a[1];
    sort(a+1,a+k+1);
    for(int i=1;i<=k;i++)
    {
      //  cout<<a[i]<<" "<<s<<endl;
        if(a[i]==s)seat=k-i+1;
    }
    //cout<<seat<<endl;
    if(((seat-1)/n)%2==0)
    {
        cout<<((seat-1)/n)+1<<" "<<((seat-1)%n)+1;
    }
    else
    {
        cout<<((seat-1)/n)+1<<" "<<m-((seat-1)%n);
    }
    return 0;
}
