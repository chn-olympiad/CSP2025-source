#include<bits/stdc++.h>
using namespace std;
int p[100010];
int cheng[100010];
int cheng2[100010];
int main()
{
    freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s=0;
    for(int i=1;i<=n*m;++i)
    {
       cin>>p[i];
        if(i==1)
        {
            s=p[i];
        }

    }
    sort(p+1,p+n*m+1);
    for(int i=1;i<=n*m;++i)
    {
       cheng[p[i]]=i;
       //cout<<p[i]<<" ";
    }//cout<<endl;
    //cout<<cheng[s]<<endl;
    int s1=n*m-cheng[s];
  // cout<<s1<<endl;
    int ms=s1/n,ns=0;
    if(ms%2==0)
    {
        ns=s1%n;
    }
    else{
        ns=n-s1%n-1;
    }
    cout<<ms+1<<" "<<ns+1;
    return 0;
}
