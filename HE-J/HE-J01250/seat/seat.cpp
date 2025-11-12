#include <iostream>
using namespace std;
int main() 
{
	int a[15][15],s[105],n,m,num;
	cin>>n>>m;
	for (int i = 1;i<n*m;i++)
	{
		cin>>s[i];
	}
	num=s[1];
	for (int i = 1;i<=n*m;i++)
	{
		for (int j = 1;j<=n*m;j++)
		{
			if (s[i]<s[i+1])
			{
				int t = s[i];
				s[i]=s[i+1];
				s[i+1]=t;
			}
		}
	}
	for (int i = 1;i<=m;i++){
		if (i%2==1){
			for (int j = 1;j<=n;j++){
				a[i][j]=s[i*j];	
			}
		}
		else{
			for (int j = n;j>=1;j--){
				a[i][j]=s[i*j];	
			}
		}
	}
	for (int i = 1;i<=m;i++){
		for (int j = 1;j<=n;j++){
			if (a[i][j]==num){
				cout<<i<<" "<<j;
				break; 
			}
		}
	}
	return 0;
}
