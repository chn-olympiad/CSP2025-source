#include<bits/stdc++.h>
using namespace std;

const int N=998244353; 

int main()
{
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	int c[n];
	int tot=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
		if(!c[i]) tot++;
	}   
	int sum=n-tot;
	
long long bbl=0;
	
	for(int i=m;i<=n;i++){
	long long ans=1;
		
		for(int j=0;j<i;j++)
		{
			if(j<=m)
			ans*=(sum-j);
			else ans*=(n-j)*(j+2);
			ans%=N;
		}
		bbl+=ans,bbl%=N;
	}
	    
	cout<<bbl;
	return 0;
}
