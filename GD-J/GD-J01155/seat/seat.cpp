#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,tmp,x,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	tmp=a[1];
	sort(a+1,a+n*m+1);
	x=lower_bound(a+1,a+n*m+1,tmp)-a;
	x=n*m-x+1;
	if(x%n==0){ 
		cout<<x/n<<" ";
		if((x/n)%2==0){
			cout<<1;
		}else{
			cout<<n;
		}
	}else{
		cout<<x/n+1<<" ";
		if((x/n+1)%2==0){
			cout<<n-(x-(x/n)*n)+1;
		}else{
			cout<<x-(x/n)*n;
		}
	}
	return 0;
}
