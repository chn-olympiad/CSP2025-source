#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],R,w;
bool cmp(long long o,long long p)
{
	return o>p;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	long long q=(n*m);
	sort(a+1,a+1+q,cmp);
	for(long long i=1;i<=q;i++)
	{
		if(a[i]==R)
		{
			w=i;
			break;
		}
	}
	if(((w-1)/n)%2==0)//ÆæÊýÁÐ 
	{
		cout<<(w-1)/n+1<<" "<<((w-1)%n)+1; 
	}
	else
	{
		cout<<(w-1)/n+1<<" "<<(n-((w-1)%n+1)+1);
	}
	return 0;
}

