//GZ-S00097 遵义市第四初级中学 周也傲 
#include <bits/stdc++.h>
using namespace std;

long long t;
 
int main(){
	freopen("club.in.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	long long out[t];
	for(int h = 0 ; h < t ; h++)
	{
		
		long long n;
		long long club1 = 0 , club2 = 0 , club3 = 0;
		cin >>n;
		long long a[n][3];
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= 3 ; j++)
			{
				cin >>a[i][j];
			}
		}
		long long sum = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			sum += max(a[i][1],max(a[i][1+1],a[i][1+2]));
			if(sum == a[i][1])
			{
				club1++;
			}
			else if(sum == a[i][1+1])
			{
				club2++;
			}
			else if(sum == a[i][1+2])
			{
				club3++;
			}
		}
		if(club1 < n/2 && club2 < n/2 && club3 < n/2)
		{
			out[h] = sum;
		}
	}
	for(int h = 0 ; h < t ; h++)
	{
		cout <<out[h]<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

