#include<bits/stdc++.h>
using namespace std;

const int N=10,M=10;

int n,m,t,x,y,dat=1;
struct node
{
    int data,grade;
}a[N*M+5];

bool cmp(node a,node b)
{
    if(a.grade==b.grade)
        return a.data<b.data;
    return a.grade>b.grade;
}
int main(void)
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    t=n*m;
    for(int i=1;i<=t;i++)
    {
        cin>>a[i].grade;
        a[i].data=i;
    }
    sort(a+1,a+1+t,cmp);
    while(a[dat].data!=1) dat++;
    y=(dat+n-1)/n;
    x=(dat-1)%n+1;
    if(y%2==0) x=n-x+1;
    cout<<y<<' '<<x;
    return 0;
}
