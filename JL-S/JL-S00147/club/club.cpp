#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	long long n, b, s1=0, s2=0, s3=0; 
	cin >> n;

	
		
		for(int j = 1; j <= n;j++)
		{
			int sum = 0;
			
			cin >> b;
			for(int k = 1; k <=b ; k++)
			{
				int a[100];
				cin >> a[j]>> a[j+1]>> a[j+2];
				if(a[j]>a[j + 1])
				{
					if(a[j]> a[j+2])
						s1+=a[j];
					
				}
					
				if(a[j+1]>a[j])
				{
					if(a[j+1]> a[j+2])
						s2+=a[j+1];
					
				}
				if(a[j+2]>a[j])
				{
					if(a[j+2]> a[j+1])
						s3+=a[j+2];
					
				}
			
		}sum = s1+ s2+ s3;
		s1 = s2 = s3 = 0;
		cout << sum;
		
	}
	
	
	return 0;
}
