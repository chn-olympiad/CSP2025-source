#include<bits/stdc++.h>
using namespace std;
int n,m,num,ans=1,x,y;
int a[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >>m;
	
	for(int i=1;i <= n;i++)
	{
		for(int j =1;j <= m;j++)
		{
			cin >> a[i][j];
			num=a[1][1];
			if(a[i][j]>num)
			{
				ans++;
			}
		}
	}
	
	if(ans%n==0){
		x=ans/n;
	}else{
		x=ans/n+1;
	}
	
	if(x%2==1){
		if(ans%n==0){
			y=n;
		}else{
			y=ans%n;
		}	
	}else{
		if(ans%n==0){
			y=1;
		}else{
			y=n-ans%n+1;
		}
		
	}
	cout<<x<<" "<< y<<endl;
	return 0;
}
