#include<iostream>
using namespace std;
int n,a[5005];
bool flag;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int p=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]!=p){
			flag=true;
			break;
		}
	}
	if(!flag){
		cout<<n-2;
		return 0;
	}
	else{
		if(n<=3){
			if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2]&&a[1]-a[2]<a[3]&&a[2]-a[3]<a[1]&&a[1]-a[3]<a[2]){
				cout<<1;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}
	}
	return 0;
}