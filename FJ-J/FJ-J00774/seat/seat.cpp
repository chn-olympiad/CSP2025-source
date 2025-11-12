#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,b;
bool B111=1,A111=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	b=a[1];
	for(int j=2;j<=m*n;j++){
		cin>>a[j];
		if(a[j]!=n*m-j+1){
			B111=0;
		}if(a[j]!=j){
			A111=0;
		}
	}
	if(A111){
		cout<<m<<" "<<n;
		return 0;
	}
	if(B111){
		cout<<"1 1";
		return 0;
	}
	sort(a+1,a+1+n*m);//greater<int>());
	b=lower_bound(a+1,a+1+n,b)-a;
	b=m*n-b+1;
	sort(a+1,a+1+n*m,greater<int>());
	if(b%n==0){
		if((b/n)%2==0){
			cout<<b/n<<" "<<1;
		}else{
			cout<<b/n<<" "<<n;
		}
	}else{
		if((b/n+1)%2==0){
			cout<<b/n+1<<" "<<n-(b%n)+1;
		}else{
			cout<<b/n+1<<" "<<b%n;
		}
	}
	return 0;
}
