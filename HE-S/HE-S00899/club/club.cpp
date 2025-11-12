#include<bits/stdc++.h>
using namespace std;
long long t,maxn = -1,minn = 100005,mid,maxnj,minnj,midj,sum = 0,i,j;
int a[100005][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int k = 1;k <= t;k ++)
	{
		long long n;
		cin >> n;
		int b[3] = {0};
		for(i = 1;i <= n;i ++)
		{
			maxn = -1,minn = 100005;
			for(j = 1;j <= 3;j ++)
			{
			
				cin >> a[i][j];
				if(maxn <= a[i][j])
				{
					maxn = a[i][j];
					maxnj = j;	
				}
				if(minn >= a[i][j])
				{
					minn = a[i][j];	
					minnj = j;
				}
				if(maxn > a[i][j] > minn)
				{
					mid = a[i][j];
					midj = j;	
				}	
			}
			sum += maxn;
			b[maxnj]++;
			if(b[maxnj] > n/2)
			{
				sum += mid;
				b[midj]++;
			}
			else if(b[midj] > n/2)
			{
				sum += minn;
				b[minnj]++; 
			}
		}
		cout << sum;
	}
	return 0;
	//保存时记得解注释 
} 
