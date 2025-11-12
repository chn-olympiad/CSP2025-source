#include<bits/stdc++.h>
using namespace std;

int a[5005];


int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int k = 0;k <= 1;k++)
		for(int b = 0;b <= 1;b++)
			for(int c = 0;c <= 1;c++)
				for(int d = 0;d <= 1;d++)
					for(int e = 0;e <= 1;e++)
						for(int f = 0;f <= 1;f++)
							for(int g = 0;g <= 1;g++)
								for(int h = 0;h <= 1;h++)
									for(int i = 0;i <= 1;i++)
										for(int j = 0;j <= 1;j++)
											if(a[1] * k + a[2] * b + a[3] * c + a[4] * d + a[5] * e + a[6] * f + a[7] * g + a[8] * h + a[9] * i + a[10] * j > 2 * (max(a[1] * k,max(a[2] * b,max(a[3] * c,max(a[4] * d,max(a[5] * e,max(a[6] * f,max(a[7] * g,max(a[8] * h,max(a[9] * i,a[10] * j))))))))))) cnt++;
								
					
	cout << cnt;
	return 0;
}
