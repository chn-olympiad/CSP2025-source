#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a=0,p=0,b=0,d=0,sum=0;
	cin>>n>>m;
	char c[n+1];
	string s;
	a=s.size();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]==0)b++;
	if(s[i]==1)d++;
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	if(n==m)cout<<1;
	if(m==1){
		p=n*n;
		cout<<p;
	}
	if(n<=10){
		if(d>=m)cout<<n*n;
			}
		for(int i=1;i<=n;i++)
	{
		
		if(c[i]>=b)
		{
			sum++;
		}
		sum=sum+d;
		cout<<sum*sum;
	}

	return 0;
}
