#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c;
	cin>>n>>m;
	int b=n*m;
	for(int i=1;i<=b;i++)
    {
        cin>>a[i];
    }
    int a1=a[1];
    sort(a+1,a+b+1);
    for(int i=b;i>=1;i--)
    {
        if(a[i]==a1)
        {
            c=b-i+1;
        }
    }
    int aa=c/n,aaa=c%n;
    int bb,d=0;
    if(c%n!=0)
    {
        aa+=1;
        d=1;
    }
    if(aa%2!=0)// ji shu
    {
        bb=aaa;
        if(d==1&&aaa==0)
        {
            bb=1;
        }
        if(d==0&&aaa==0)
        {
            bb=n;
        }
    }
    else//ou shu
    {
        bb=n-aaa+1;
        if(d==1&&aaa==1)
        {
            bb=n;
        }
        if(d==0&&aaa==0)
        {
            bb=1;
        }
    }
    cout<<aa<<" "<<bb;
	return 0;
}
