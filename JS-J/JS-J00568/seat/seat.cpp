#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt=1,cnt2=1;
    cin>>n>>m;
    int x=n*m;//all
    int a[x];
    int b[x];
    for(int i=0;i<=x-1;i++)
        cin>>a[i];
    int an=a[0];
    for(int j=0;j<=x-1;j++){
        int maxi=0;
        for(int i=0;i<=x-1;i++)
        {
            if(a[i]>maxi)
                maxi=a[i];
        }
        b[j]=maxi;
        for(int i=0;i<=x-1;i++)
            if(a[i]==maxi)a[i]=0;
    }
    for(int i=0;i<=x-1;i++)
    {
        if(b[i]==an)cnt2=cnt;
        else cnt+=1;
    }
    if(cnt2%n==0)
    {
        if((cnt2/n)%2==1)
            cout<<cnt2/n<<" "<<n<<endl;
        else
            cout<<cnt2/n<<" "<<1<<endl;
    }
   else
   {
        if((cnt2/n)%2==1)cout<<(cnt2/n)+1<<" "<<cnt2-(cnt2/n)<<endl;
        else cout<<cnt2/n+1<<" "<<cnt2-(cnt2/n)*n<<endl;
   }

    return 0;
}

