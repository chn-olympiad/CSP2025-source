#include<iostream>
#include<algorithm>
using namespace std;
int a[10005];
bool cmp(int x,int y)
{

    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,ans,ansh;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {

        cin>>a[i];
        if(i==1)ans=a[i];
    }
    sort(a+1,a+1+n*m,cmp);
     for(int i=1;i<=n*m;i++)
    {
       
        if(a[i]==ans)
        {

            ans=i;
            break;
        }

    }
    ansh=(ans-1)/n+1;
    if(ansh%2==1)
    {

        cout<<ansh<<" "<<ans-((ansh-1)*n);
    }
    else{
        cout<<ansh<<" "<<n*ansh-ans+1;
    }
    return 0;

}