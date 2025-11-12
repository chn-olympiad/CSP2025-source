#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int rc,nc,cnt = 1;
	cin>>rc;
	for(int i = 1;i < n*m;i++)
	{
		cin>>nc;
		if(rc < nc) cnt++;
	}
	if(((cnt-1)/n)&1)
	cout<<(cnt-1)/n+1<<" "<<n-((cnt-1)%n);
	else cout<<(cnt-1)/n+1<<" "<<((cnt-1)%n+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
