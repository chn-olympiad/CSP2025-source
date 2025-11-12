#include<bits/stdc++.h>

using namespace std;

int t, n, a[100010][5], b[5], ma, mad[100010], c[100010], d[100010], sum;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		scanf("%d", &n);
		sum = 0;
		int x[100010];
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= 3; k++)
				scanf("%d", &a[j][k]);
		for (int j = 1; j <= 3; j++)
			b[j] = 0;
		for (int j = 1; j <= n; j++){
			ma = 0;
			for (int k = 1; k <= 3; k++){
				if (a[j][k] > ma){
					ma = a[j][k];
					mad[j] = k;
				}
			}
			//cout << mad[j] << " ";
			if (mad[j] == 1)
				c[j] = ma - a[j][2], d[j] = ma - a[j][3];
			else
				if (mad[j] == 2)
					c[j] = ma - a[j][1], d[j] = ma - a[j][3];
				else
					c[j] = ma - a[j][1], d[j] = ma - a[j][2];
			b[mad[j]]++;
			sum += ma;
		}
		int t = 0, tt = 0, k;
		//cout  << "\n"<< b[1]  << " "<< b[2]<< " " << b[3] << "\n";
		for (int j = 1; j <= 3; j++)
			if (b[j] > n / 2)
				t = j;
		k = b[t] - n/2;
		for (int j = 1; j <= n; j++){
			if (mad[j] == t)	
				x[++tt] = min(c[j], d[j]);
		}
		sort(x+1, x+tt+1);
		for (int j = 1; j <= k; j++)
			sum -= x[j];
		printf("%d\n", sum);
	}
	
} 
