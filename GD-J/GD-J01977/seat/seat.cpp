#include <bits/stdc++.h>
using namespace std;
int n,m,c,r,a[110],t;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1);
	int j=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==t){
			t=j;
		}
		j++;
//		cout<<a[i]<<' ';
	}
//	cout<<t<<" ";
	if(t%n){
		c=t/n+1;
	}else{
		c=t/n;
	}
	if(c%2==0){
		if(t%n==0){
			r=1;
		}else{
			r=n-t%n+1;
		}
	}else{
		r=t%n;
	}
	if(r==0)r=n;
	if(c==0)c=m;
	cout<<c<<' '<<r;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
//3 3
//94 95 96 97 98 99 100 93 92

//2 2
//97 100 99 98
