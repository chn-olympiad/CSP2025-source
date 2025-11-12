#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[105],x,ansx,ansy;
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+1+s,cmp);
	for(int i=1;i<=s;i++)
	{
		if(a[i]==x)
		{
			ansx=i/m;
			if(i%m) ansx++;
			i-=ansx*m-m;
			if(ansx%2) ansy=i;
			else ansy=n-i+1;
			cout<<ansx<<" "<<ansy<<endl;
			return 0;
			
		}
	}
	return 0;
}
