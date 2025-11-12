#include<bits/stdc++.h>
#define io freopen("seat.in","r",stdin),freopen("seat.out","w",stdout)
using namespace std;
int n,m,ansc,ansr;
int a[110];
bool cmp(int A,int B)
{
    return A>B;
}
int main()
{
    io;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int target=a[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=i;j<=n*m;j++)
        {
            if(a[i]<a[j])swap(a[i],a[j]);
        }
    }
    //for(int i=1;i<=n*m;i++)cout<<a[i]<<endl;
    for(int i=1;i<=n*m;i++)
        if(a[i]==target){target=i;break;}
    //cout<<target<<endl;
    ansc=(target-1)/n+1;
    ansr=(target-1)%n+1;
    if(ansc%2==0)ansr=n+1-target;
    cout<<ansc<<" "<<ansr<<endl;
    return 0;
}
