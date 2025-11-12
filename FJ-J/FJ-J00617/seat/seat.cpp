#include<bits/stdc++.h>
using namespace std;
long long a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,sum=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==x){
			break;
		}
		sum++;
	}
	int c=sum/n;
	bool bd=1;
	if(sum/n==0){
		c=1;
		bd=0;
	}
	if(sum%n!=0&&bd){
		c++;
	}
	int r=sum%n;
	if(r==0){
		if(c%2==1){
			r=n;
		}else{
			r=1;
		}
	}else{
		if(c%2==0){
			r=n-r+1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
} 
