#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[110],a1;
bool b(int a,int b){
	return a>b;
}int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	a1=a[1];
	sort(a+1,a+n*m+1,b);
	for(int i=1;i<=n*m;i++){
		if(a1==a[i]){
			a1=i;
			break;
		}
	}if(!(a1%n)){
		cout<<a1/n<<' ';
		if((a1/n)%2)cout<<n;
		else cout<<1;
	}else{
		cout<<a1/n+1<<' ';
		if((a1/n+1)%2)cout<<a1%n;
		else cout<<n-a1%n+1;
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
