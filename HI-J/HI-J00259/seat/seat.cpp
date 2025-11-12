#include<bits/stdc++.h>
using namespace std;
int x[1005];
bool cmp(int a,int b){
	if(a>b){
		return a>b;
	}
	else if(a<b){
		return a<b;
	}
}
int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	int a,b;
	cin>>a>>b;
	int z[a][b];
	for(int i=1;i<=a*b;i++){
		cin>>x[i];
	}
	int xr=x[1];
	sort(x+0,x+a*b,cmp);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			z[i][j]=x[i+j];
				if(z[i][j]==xr)
		{
			cout<<i<<" "<<j;
			break;
		}
	}
}
	return 0;
} 
