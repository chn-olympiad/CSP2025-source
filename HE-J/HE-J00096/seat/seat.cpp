#include<iostream>
#include<algorithm>
using namespace std;
int n,m,num[11][11],a[105],x=1,y=1,s,q;
int main()
{
cin>>n>>m;
for(int i=1;i<=n*m;i++)
{
cin>>a[i];
}
s=a[1];
sort(a+1,a+n+1);
for(int i=1;i<=n*m;i++)
{
if(s==a[i])
{
q=i;


break;
}

}

int h=1;
for(int i=n*m;i>q;i--)
{

if(x+h>n||x+h<1)
{
y++;
h*=-1;
continue;
}
x+=h;
}
cout<<y<<" "<<x;
return 0;
}
