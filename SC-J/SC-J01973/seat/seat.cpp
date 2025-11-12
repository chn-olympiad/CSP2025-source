#include<bits/stdc++.h>//b-seat
using namespace std;
int n,m;//10/10
int idx=1;//100
int l,h;//m/n
int a[1006];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i!=1&&a[i]>a[1]) ++idx;
	}
	l=(idx-1)/n+1;
	h=0;
	if(l%2==1)
	{
		h=idx%n;
		if(h==0) h=n;
	}
	else
	{
		h=n-(idx%n)+1;
		if(idx%n==0) h=1;
	}
	cout<<l<<' '<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
out:先列再行！！！ 
 
n行m列的矩阵！
从高到低
互不相同 

yl:
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

zc:
4 2
1 2 3 4 5 6 7 8

4 2
8 7 6 5 4 3 2 1
*/ 