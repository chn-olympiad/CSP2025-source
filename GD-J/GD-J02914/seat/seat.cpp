#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int n,m,r,t,ans,x,y;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++)
	{
		scanf("%d",&t);
		if(i==0) r=t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	t=0;
	while(v[t]<r) t++;
	t=n*m-t,x=t/n+1,y=t%n;
	if(y==0) x--,y+=n;
	if(x%2==0) y=n+1-y;
	printf("%d %d",x,y);
	return 0;
}
