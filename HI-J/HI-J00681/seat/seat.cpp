#include<bits/stdc++.h>
using namespace std;

int n,m,a[110];
bool abc(int a,int b)
{
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)	cin >> a[i];
	int flag = a[1];
	sort(a+1,a+n*m+1,abc);
	int w;
	for (int i = 1;i <= n*m;i++)
		if (a[i] == flag)	w = i;
	
	int l,h;
	if (w % n != 0)	l = w/n+1;
	else  l = w/n;
	if (l % 2 == 0)  h = n*l+1-w;
	if (l % 2 == 1)
	{
		if (w % n != 0)	h = w % n;
		else  h = w/n+1;
	}
	cout << l << ' ' << h;
	return 0;
} 
