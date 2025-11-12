#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],al;
bool cmp(int a,int b) {return a>b;}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int al=n*m;
    for(int i=1;i<=al;i++) cin>>a[i];
    int target=a[1],p;
    sort(a+1,a+al+1,cmp);
    for(int i=1;i<=al;i++)
        if(a[i]==target) {p=i; break;}
    //for(p=1;p<=100;p++)
    //{
    int column=p/n+int(bool(p%n)),row;
    if(column%2==1)
        {row=p%n; if(row==0) row=n;}
    else if(column%2==0)
        {row=n-p%n+1; if(row==n+1) row=1;}
    cout<<column<<" "<<row<<endl;
    //}
    return 0;
}
