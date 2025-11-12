#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seatin","r",stdin);
    freopen("seatout","w",stdout);
    int n,m;
    cin>>n>>m;//n lie,m hang
    int num,maxx=0;
    int sum=0;
    for(int i=0;i<n*m;i++)
    {
        cin>>num;
        if(num>maxx)
        {
            maxx=num;
            sum++;
        }
    }
    if(sum<=n)
    {
        cout<<"1"<<" "<<sum;
    }
    else if(sum>n and (sum+1)%n==0)
    {
        cout<<sum/n+1<<" "<<(sum+1)/n;
    }
    else if(sum+1>n and (sum+1)%n>=1)
    {
        cout<<sum/n+1<<" "<<(sum+1)%n+1;
    }
    return 0;
}
