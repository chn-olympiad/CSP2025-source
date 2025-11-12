#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int me=0,a,h;
	double l;
	int more = n*m;
	int seat[more];
	for(int i=1;i<=more;i++)
	{
		cin >> seat[i];
		me = seat[1];
	}
	for(int i=1;i<=more;i++)
	{
		for(int j=1;j<=more;j++)
		{
			if(seat[i]>=seat[j])
			{
			 a = seat[i];
			 seat[i] = seat[j];
			 seat[j] = a;	
			} 
		}
	}
	for(int i=0;i<=more;)
	{
		i++;
		if(me==seat[i])
		{
			if(i%n==0)
			{
				h = n - i%n;
			}else{
				h = (n+1) - i%n;
			}			
			if(i%n!=0)
			{
				l = i/n + 1;
			}else{
				l = i/n;
			}
			cout << l << " "<< h;
		}
	}
	
} 
