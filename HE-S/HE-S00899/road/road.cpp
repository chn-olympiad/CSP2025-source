#include<bits/stdc++.h>
using namespace std;
long long n,m,k,minn = 1000000,sum = 0;
int a[15][1000005],b[100000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> >> n >> m >> k;
	for(int j = 1;j <= m;j ++)
	{
		long long c1,c2;
		cin >> c1 >> c2 >> b[j];
		if(minn > b[j])
		{
			minn = b[j];
		}
		for(int i = 1;i <= k;i ++)
 		{
 			long long sc;
			cin >> sc >> a[j][i];	
		}
		if(1<=j<=k&&1<=i<=n)
		{
			sum += minn;
		}
 	} 
 	cout << sum;    
	return 0;
	//保存时记得解注释 
} 
