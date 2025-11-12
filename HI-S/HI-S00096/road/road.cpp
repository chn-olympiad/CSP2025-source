#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
long long n,m,ans;
struct ab{
	int a,b,c;
}l[M];
int a[M];
int px(ab a,ab b)
{
	return a.c<b.c;
}
	int p;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>l[i].a>>l[i].b>>l[i].c;
	}
	sort(l+1,l+1+m,px);
	for(int i=1;i<=m;i++)
	{
		//cout<<a[l[i].a]<<" "<<a[l[i].b]<<" "<<l[i].a<<" "<<l[i].b<<"\n";
		if(a[l[i].a]==0||a[l[i].b]==0)
		{
			ans+=l[i].c;
			a[l[i].a]=1;
			a[l[i].b]=1;
		}
	}
	cout<<ans;
	return 0;
} 
