#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m;
int r;
int idx;
bool cmp(int p,int q)
{
	return p>q;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r) 
		{
			idx=i;
			break;
		}
	}
	//cout<<idx<<endl;
	int xx=(idx%n==0 ? idx/n : idx/n+1);
	cout<<xx<<' '<<(xx%2==1 ? (idx%n!=0 ? idx%n : n) : n-(idx%n!=0 ? idx%n : n)+1)<<endl;
	return 0;
} 