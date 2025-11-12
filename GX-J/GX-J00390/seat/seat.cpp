#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int a1;
	int a[101];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	for(int i=2;i<=n*m;i++){
	if(a[i]>a[i-1]){
			int x=a[i-1];
			a[i-1]=a[i];
			a[i]=x;
	}
	}
	int h;
	int l;
	for(int j=1;j<=n*m;j++)
	{
		if(a[j]==a1)
		{
			if(j%n==0)
			{
				l=j/n;
				if(l%2==0)
				{
					h=1;
				}
				else
				{
					h=n;
				}
			}
			else
			{
				l=j/n+1;
				if(l%2!=0)
				{
					h=j%n;
				}
				else
				{
					h=n-(j%n)+1;
				}
			}
		}
	}
	cout<<l<<h;
	
	return 0;
	
}
