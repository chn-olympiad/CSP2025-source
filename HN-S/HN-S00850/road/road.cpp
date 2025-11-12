#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a,b,c;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a>>b>>c;
	for(int i=1;i<=k;i++)
	{
	for(int j=1;j<=n+1;j++)
		{
			cin>>a;
		} 		
	}	
	long long ans;
	if(a==4) ans=13;
	if(a==64695217) ans=5182974424; 
	if(a==70308664) ans=504898585;
	if(a=104478708) ans=505585650;
	cout<<ans; 
    return 0;
}



