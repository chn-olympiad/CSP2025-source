#include <bits/stdc++.h>
using namespace std;
int a[11100];
bool p(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1],s=0;
	sort(a+1,a+n*m+1,p);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			s=i;
		}
	}

	int y=0;
	if(s%n==0){
		y=s/n;
	}else{
		y=s/n+1;
	}
	cout<<y<<' ';
	int l=s-(y-1)*n;
	if(y%2==1){
		cout<<l;
	}else{
		cout<<n-l+1;
	}
	return 0;
} 
