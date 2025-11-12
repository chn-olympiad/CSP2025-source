#include<bits/stdc++.h>
using namespace std;
int n,m;
int zs,a1;
int a[1000];
int wz;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	zs=n*m;
	for(int i=1;i<=zs;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+zs+1,cmp);
	for(int i=1;i<=zs;i++){
		if(a[i]==a1){
			wz=i;
			break;
		}
	}
	if(wz%n==0){
		int x=0;
		if((wz/n)%2==0){
			x=1;
		}else{
			x=n;
		}
		cout<<wz/n<<" "<<x;
		return 0;
	}
	int x=wz/n+1;
	if(x%2==1){
		cout<<x<<" "<<wz%n;
	}else{
		cout<<x<<" "<<n-wz%n+1;
	}
	return 0;
}
