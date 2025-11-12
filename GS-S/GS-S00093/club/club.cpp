#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int t, n, tn[3];
int sum;

struct A{
	int a[3], num, ma, minus;//ai[j] i max - 
}a[100002];

bool CMD(A x, A y)
{
	if ( x.minus == y.minus )
	{
		if ( x.ma == y.ma )
			return x.num < y.num;
		return x.ma > y.ma;
	}
	return x.minus < y.minus;
}

int WH(int i)
{
	int ma, tmi=-114514;//num t
	for ( int j = 0; j < 3; j++ ){
		if ( tn[j]>0 ){
			if ( tmi < a[i].a[j] ){
				ma = j;
				tmi = a[i].a[j];
			}
			else if ( tmi == a[i].a[j] ){
				if ( tn[ma]<tn[j] )
				  ma == j;
			}
		}
	}
	tn[ma]--;
	return ma;
}

int main()
{
	freopen("club.in","r" , stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	int ma;
	while ( t-- )
	{
		cin >> n;
		tn[0]=tn[1]=tn[2]=n/2;
		sum=0;
		for ( int i = 0; i < n; i++ ){//cin
			ma=-1;
			a[i].num=i;
			for ( int j = 0; j < 3; j++ ){
				cin >> a[i].a[j];
				ma=max(ma,a[i].a[j]);
			}
			a[i].ma = ma;
			for ( int j = 0; j < 3; j++ ){
				a[i].a[j]-=ma;
			}
			a[i].minus = a[i].a[0]+a[i].a[1]+a[i].a[2];
		}
		sort(a,a+n,CMD);
		for ( int i = 0; i < n; i++ ){
			sum+=a[i].ma+a[i].a[WH(i)];
		}
		cout << sum << '\n';
		/*
		for ( int i = 0; i < n; i++ ){
			for ( int j = 0; j < 3; j++ )
				cout << a[i].a[j] << ' ';
			cout << a[i].num << ' ' << a[i].ma << ' ' << a[i].minus << '\n';

		}
		*/
	}
	return 0;
}
