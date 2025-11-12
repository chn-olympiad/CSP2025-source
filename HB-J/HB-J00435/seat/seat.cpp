#inculde<bits/stdc++.h>;
using namespace;
int a[105];
int main{
	freopen(seat.in stdin.r);
	freopen(seat.out stdout.w);
	for(int i=1;i<=105;i++){
		a[i]=0;
	}
	int n=0,m=0,c=0,r=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		int t=1;
		if(a[i]>a[1]){
			t++;
		}
	}
	c=t/m;
	if(c%2!=0){
		r=t%n;
	}
	if(c%2==0){
		r=n-(t%n);
	}
	cout<<c<<' '<<r<<endl;
	return 0;
}
