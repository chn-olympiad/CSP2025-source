#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x=1,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if((x==n&&y%2==1)||(x==1&&y%2==0))y++;
		else if(y%2==1)x++;
		else x--;
		if(a[i]==s)
		{
			cout<<y<<" "<<x;
			return 0;
		}
	}
	return 0;
}
