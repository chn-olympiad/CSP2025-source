#include<bits/stdc++.h> 
using namespace std;
int n,i,j,a[35];
long long ds(long long y,long long h)
{
	long long sum=0;
	if(y==2){
		if(a[1]>h) return sum+1;
		else return sum;
	}
	long long pp=h-a[y-1];
	for(int o=y-1;o>=2;o--){
		sum+=ds(o,pp);
	}
	if(y>3)sum+=ds(y-1,h-a[y]);
	return sum;
}
int main ()
{
freopen(" polygon.in","r",stdin);
freopen(" polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
	if(a[1]+a[2]>a[3])
		cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<ds(n+1,a[n]*2);
	return 0;
}
