#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,k,c,h=1,l,cnt=1;
    cin>>n>>m>>k;
    a[1]=k;
    for(int i=2;i<=n*m;i++)
    {
		cin>>a[i];
    }
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;i--)
    {
		if(a[i]==k)
		{
			c=cnt;
			break;
		}
		cnt++;
	}
	while(c>n)
	{
		c-=n;
		h++;
	}
	if(h%2==1)l=c;
	else l=n-c+1;
    cout<<h<<' '<<l;
    return 0;
}
