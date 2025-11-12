#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],id;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	id=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==id)
		{
			int x=(i/n)+((i%n)!=0);
			int y=(x%2==1?(i-1)%n+1:n-((i-1)%n));
			cout<<x<<" "<<y;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
