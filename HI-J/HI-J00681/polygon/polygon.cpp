#include<bits/stdc++.h>
using namespace std;

int n,a[5010],b,c,sum = 0; 

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)  cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 3;i < n;i++){
		for (int j = 1;j <= n;j++){
			for (int z = j;z <= i + j;z++){
				b += a[z];
				c = a[z+j];
			}
			if (b>c*2)  sum++; 
		}
	} 
	cout << sum;
	return 0;
} 

