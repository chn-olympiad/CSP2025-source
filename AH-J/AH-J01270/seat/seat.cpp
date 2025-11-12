#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,j,w;
    int sc[105];
    cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>sc[i];
	}
	j=sc[1];
	sort(sc+1,sc+n*m+1,greater<int>());
	for(int i=1;i<=m*n;i++)
	{
		if(sc[i]==j)
		{
			w=i;
			break;
		}
	}
	if(((w-1)/n+1)%2==1)
	cout<<(w-1)/n+1<<" "<<(w-n*((w-1)/n));
	else
	cout<<(w-1)/n+1<<" "<<n-(w-n*((w-1)/n))+1;
	return 0;
}
