#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],s,t,x,y,c,r;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
		cin>>a[i];
	s = a[1];
	for(int i = 1;i<n*m;i++)
		for(int j = 1;j<=n*m-i;j++)
			if(a[j] < a[j+1])	swap(a[j],a[j+1]);
	for(int i = 1;i<=n*m;i++)
		if(a[i] == s)
			t = i;
	if(t<=n){
		cout<<1<<" "<<t;
		return 0;
	}
	else{
		x = t / n;
		y = t % n;
		c = x + 1;
		if(y == 0)	r = n;
		if(x % 2 == 1)	r = n-y+1;
		else r = y;
	}
	cout<<c<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}