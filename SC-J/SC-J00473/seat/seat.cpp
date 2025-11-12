#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int>a(n*m);
	for(int i=0;i<n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a.begin()+1,a.end(),comp);
	for(int i=1;i<n*m;i++)
	{
		if(a[i]<a[0])
		{
			int idx=i-1;
//			cout<<idx<<endl;
			cout<<(idx/n+1)<<" "<<((idx/n)%2==0?idx%n+1:n-idx%n)<<endl;
			return 0;
		}
//		cout<<a[i]<<" ";
	}
	return 0;
}
