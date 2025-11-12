#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1005],s;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+s+1,cmp);
	for(int i=1;i<=s;i++){
		if(k==a[i]){
			k=i;
		}
	}
	int x1=k/n,x2=k%n;
	if(x2>0){
		if((x1+1)%2==0){
			cout<<x1+1<<" "<<n-x2+1;
		}
		else{
			cout<<x1+1<<" "<<x2;
		}
	}
	else if(x2==0 && x1%2==0){
		cout<<x1<<" "<<1;
	}
	else{
		cout<<x1<<" "<<n;
	}
	return 0;
}
