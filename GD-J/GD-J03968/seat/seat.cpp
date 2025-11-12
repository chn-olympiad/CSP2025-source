#include<bits/stdc++.h>
using namespace std;
int n,m;
int kl[110];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>kl[i];
	}
	int r=kl[1];
	sort(kl+1,kl+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(kl[i]==r)
		{
		
			int xx=i/m;
			if(i%m)xx+=1;
			if(xx%2)
			{
				if(i%m==0)cout<<xx<<" "<<m;
				else cout<<xx<<" "<<(i%m);
			}
			else
			{
				if(i%m==0)
				{
					cout<<xx<<" "<<m;
				}
				else
				cout<<xx<<" "<<m-(i%m)+1;
			}
			break;
		}
	}
	return 0;
}
