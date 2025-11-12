#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=m*n;i++)	cin>>a[i];
	int cnt = 1;
	for(int i = 2;i<=m*n;i++){
		if(a[i] > a[1])	cnt++;	//ÊıÃû´Î 
	}
	c = (cnt + n - 1)/n;
	r = cnt % n;
	if(r == 0)	r=n;
	if(c % 2 == 0)	r = n + 1 - (cnt % n);
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
