#include <bits/stdc++.h>
using namespace std;

const int MAXN=5000+5;
int n, num[MAXN], ans;
int sum, maxn;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d", &num[i]);
	
	if (n<3)
		ans=0;
	else if (n==3)
	{
		if(num[0]+num[1]+num[2]>2*max(num[0], max(num[1], num[2])))
			ans++;
	}
	else if (n==4)
	{
		for (int i=0; i<n-2; i++)
			for (int j=i+1; j<n-1; j++)
				for (int k=j+1; k<n; k++)
					if (num[i]+num[j]+num[k]>2*max(num[i], max(num[j], num[k])))
						ans++;
		if(num[0]+num[1]+num[2]+num[3]>2*max(max(num[0], num[1]), max(num[2], num[3])))
			ans++;
	}
	else if (n==5)
	{
		for (int i=0; i<n-2; i++)
			for (int j=i+1; j<n-1; j++)
				for (int k=j+1; k<n; k++)
					if (num[i]+num[j]+num[k]>2*max(num[i], max(num[j], num[k])))
						ans++;
		for (int i=0; i<n-3; i++)
			for (int j=i+1; j<n-2; j++)
				for (int k=j+1; k<n-1; k++)
					for (int l=k+1; l<n; l++)
						if (num[i]+num[j]+num[k]+num[l]>2*max(max(num[i], num[j]), max(num[k], num[l])))
							ans++;
		if(num[0]+num[1]+num[2]+num[3]+num[4]>2*max(max(num[0], num[1]), max(num[2], max(num[3], num[4]))))
			ans++;
	}
	
	printf("%d", ans);
	return 0;
}