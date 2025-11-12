#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],xr;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
		if(i==1) xr=a[i];
	}
	sort(a+1,a+sum+1,cmp);
	int k;
	for(int i=1;i<=sum;i++){
		if(a[i]==xr) k=i;
	}
	int x=k/n;
	int y=k%n;
	if(y==0){
		if(x%2==0){
			cout<<x<<' '<<1<<endl;
	}
		else {
			cout<<x<<' '<<n<<endl;
		}
	}
	else if(x%2==0){
		cout<<x+1<<' '<<y<<endl;
	}
	else if(x%2!=0){
		cout<<x+1<<' '<<n-y+1<<endl;
	}
	return 0;
}