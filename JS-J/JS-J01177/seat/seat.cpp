#include<bits/stdc++.h>
using namespace std;

int n,m,sum,num;
int a[100009];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    sum=n*m;
    for(int i=1;i<=sum;i++)
    {
        cin>>a[i];
    }
    num=a[1];
    sort(a+1,a+sum+1,greater<int>());
    int x=1,y=1,fx=1;
    for(int i=1;i<=sum;i++)
    {
        if(a[i]==num)
        {
            cout<<y<<" "<<x;
            return 0;
        }
        if(x+fx>n||x+fx<1)
        {
            fx=-fx;y++;
        }
        else
        {
            x+=fx;
        }
    }


    return 0;
}
