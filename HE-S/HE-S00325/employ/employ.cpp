#include<bits/stdc++.h> 
using namespace std;
long long n,m,p=1,q=1;
char b[505];
bool a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	m=m;
	for(int i=1;i<=n;i++)
		{
			p*=i;
		}
	for(int i=1;i<=n;i++)
	{cin>>b[i];
		if(b[i]==49) 
		{a[i]=true;
		}
		else 
		{a[0]=true;
		}
	}
	if(m==1)
	{while(cin>>q)
	{
		if(q!=1)
		break;
	}
		if(a[1]==1) 
		{
			cout<<p;
			return 0;
		}
		else if(q==1)
		{
			cout<<0;
			return 0;
		}
		else if(a[2]==1) 
		{
			cout<<p;
			return 0;
		}
		else
		cout<<0;
	}
	if(a[0]) {
		if(m==n)
		cout<<0;
		else
		cout<<2*m-2;
	}
	else
	{
		cout<<p;
	}
	return 0;
}
