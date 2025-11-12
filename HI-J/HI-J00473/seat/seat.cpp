#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
    int a[10005];
    int x=n*m;
	for(int i=1;i<=x;i++) cin>>a[i];	
	int r=a[1];
	sort(a+1,a+x+1);
	int q[10005];
	for(int i=1;i<=x;i++) q[i]=a[i];
    for(int i=0;i<=x;i++)
    {
    	if(i==0)a[i+1]=q[x];
		else
		{
			a[i+1]=q[x-i];
		}
	}
    int y=0;
	for(int i=1;i<=x;i++)
 	{
		if(a[i]==r) y=i;
	} 
    int z=0;
	if(y%m==0) z=y/m;
	else z=y/m+1;
    if(z==1) 
	{
		cout<<z<<" "<<y;
		return 0;
	}
	if(z%2==1) 
	{
		cout<<z<<" "<<y%n;
	}
	else cout<<z<<" "<<y%n+1;
    
	return 0;
}


