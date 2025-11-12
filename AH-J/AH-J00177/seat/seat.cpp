#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b[150],c;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>b[i];
	c=b[1];
    sort(b+1,b+n*m+1);
    for(int i=1;i<=n*m;i++)
    if(b[n*m+1-i]==c){
		cout<<(i-1)/n+1<<' ';
		if(((i-1)/n+1)%2==0)cout<<n-((i-1)%n+1)+1;
		else cout<<(i-1)%n+1;
		break;
	}
	return 0;
}
