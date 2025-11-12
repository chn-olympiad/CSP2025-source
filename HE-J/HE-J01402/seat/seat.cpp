#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int a[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int o=1;
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]&&i!=1){
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
			if(a[i]<a[j]&&i==1){
				int tmp=a[i];
				o=j;
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	if(o>n&&o%n!=0){
		cout<<o/n+1<<' '<<o%n;
		return 0;
	}
	if(o>n&&o%n==0){
		cout<<o/n<<' '<<n;
		return 0;
	}
	if(o<n){
		cout<<n-o<<' '<<1;
		return 0;
	}
	if(n==o){
		cout<<1<<' '<<n;
		return 0;
	}
	return 0;
}
