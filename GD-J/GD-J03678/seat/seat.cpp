#include <bits/stdc++.h>
using namespace std;
int b[225];
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s;
	cin>>s;
	b[1]=s;
	for(int i=2;i<=n*m;i++) cin>>b[i];	
	sort(b+1,b+1+n*m,cmp);
	int x;
	for(int i=1;i<=n*m;i++)
	{
		if(b[i]==s)
		{
			x=i;
			break;	
		} 	
	} 
	int w=(x+n-1)/n;
	if(w%2==1)
	{
		cout<<w<<" "<<x%n;
	}
	else
	{
		cout<<w<<" "<<n-x%n;
	}
	return 0;
} 
