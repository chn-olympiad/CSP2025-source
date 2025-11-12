#include<bits/stdc++.h>
using namespace std;

int n,m,ber;
int num[105];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++){
		int res;
		cin >> res;
		num[i] = res;
	}
	int con = num[1];
	sort(num+1,num+n*m+1);
	for (int i = 1;i <= n*m;i++){
		if (num[i] == con) ber = i;
	}
	ber = n*m-ber+1;
	int l=0,h=0;
	if (ber%n == 0) l = ber/n;
	else l = (ber-(ber%n))/n+1;
	if (l % 2 == 1) h = ber-(n*(l-1));
	else h = n-(ber-(n*(l-1)))+1;
	cout << l << ' '  << h;
	return 0;
}
