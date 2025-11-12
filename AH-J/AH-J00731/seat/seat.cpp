#include<bits/stdc++.h>
using namespace std;

long long n,m,a[225];

int cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long a1=a[1];
	sort(1+a,1+a+n*m,cmp);
	int i=1;
	while(a[i]!=a1){
		i++;
	}
	cout<<i<<endl;
	long long lie =(i%n==0 ? i/n : i/n+1),hang;
	if(lie%2==1){
		hang=(i%n==0? n:i%n);
	}
	else if(lie%2==0){
		hang=n-i%n+1;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
