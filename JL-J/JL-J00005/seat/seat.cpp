#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ansc,ansr;
int a[1000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int R=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==R)
        {
            cnt=i;
            break;
        }
    }
    if(cnt%n==0)ansc=cnt/n;
    else ansc=cnt/n+1;
    ansr=cnt-((ansc-1)*n);
    if(ansc%2==0)ansr=n-ansr+1;
    cout<<ansc<<" "<<ansr;
    return 0;
}
