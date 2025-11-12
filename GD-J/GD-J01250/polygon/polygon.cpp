#include <bits/stdc++.h>
using namespace std;

int n,x = 0,a[5001];

int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(int i = 1;i <= n - 2;i++)
		for(int j = i + 1;j <= n - 1;j++)
			for(int k = j + 1;k <= n;k++)
				if(a[i] + a[j] > a[k] && a[i] + a[k] > a[j] && a[j] + a[k] > a[i]) ++x;
	printf("%d",x);
}
