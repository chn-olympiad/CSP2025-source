#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,m;
int tt,cnt=1;
int s;
int main()
{
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		cin>>n>>m;
		cin>>tt;
		int x;
		for(int i=1;i<=n*m-1;i++)
		{
			cin>>x;
			if(x>tt) cnt++;
		}
		s=cnt/n;
		if(cnt%n!=0) s++;
		if(s%2==0)
		{
			if(cnt%n==0) cout<<s<<" "<<1;
			else cout<<s<<" "<<n-(cnt%n)+1;
			return 0;
		}
		else
		{
			if(cnt%n==0) cout<<s<<" "<<n;
			else cout<<s<<" "<<cnt%n;
			return 0;
		}
		return 0;
}

