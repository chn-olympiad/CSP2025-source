#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,a[500];
	cin>>n>>m;
	cin>>a1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+2,a+n*m+1);
	for(int i=m*n;i>=2;i--){
		if(a1>a[i]){
			a1=m*n-i+1;
			break;
		}
	}
	if(a1%n==0){
		cout<<a1/n<<' ';
	}else if(a1%n!=0){
		cout<<(a1/n)+1<<' ';
	}
	if(a1%n==0&&a1/n%2==1){
		cout<<m;
	}else if(a1%n==0&&a1/n%2==0){
		cout<<1;
	}else if(a1%n!=0&&a1/n%2+1==1){
		cout<<a1%n;
	}else if(a1%n!=0&&a1/n%2+1==0){
		cout<<m-a1%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
