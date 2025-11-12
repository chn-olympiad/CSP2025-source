#include<bits/stdc++.h>
using namespace std;
int a[20][20],b[105];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>b[i];
	for(int i=1;i<=n*m-1;i++)
	{
		for(int j=i;j<=n*m-1;j++)
		{
			if(b[i]<b[i+1])swap(b[i],b[i+1]); 
		}
	}
	
	return 0;
}
