#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    //long long file memory
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int rnk=0;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>=a[1])
        {
            rnk++;
        }
    }
    int ansr=0,ansc=0;
    ansc=(rnk-1)/n+1;
    ansr=(rnk-1)%n;
    if(ansc%2==0)
    {
        ansr=n-ansr;
    }
    else
    {
        ansr++;
    }
    cout<<ansc<<' '<<ansr<<endl;
    return 0;
}
