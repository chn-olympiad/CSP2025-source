#include<bits/stdc++.h>
using namespace std;
long long n, a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	long long maxa=0,suma=0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		maxa = max(maxa,a[i]);
		suma +=a[i];
	}
	if(maxa <=1){
		if(maxa == 0){
			cout << 0;
			return 0;
		}
		else cout << suma * (suma-1) * (suma-2) / 6 %998244353;
	}
	if (n <= 3)
	{
		if(maxa*2<suma){
			cout << 1;
		}
		else{
			cout << 0;
		}
		return 0;
	}
		maxa=0;
		suma=0;
		int cnt = 0;
		do
		{
			for(int i = 1; i <= n; i ++){
				maxa = max(maxa,a[i]);
				suma += a[i];
				if(maxa * 2<suma && i>=3){
					cnt++;
				}
			}
		} while (next_permutation(a+1,a+n+1));
		cout << cnt;
	return 0;
}
