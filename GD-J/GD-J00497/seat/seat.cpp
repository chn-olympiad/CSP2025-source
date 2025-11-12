#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],b,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n>> m;
	for(int i=1;i<=n*m;i++){
		cin>> a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1,greater<long long>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			c=i;
			break;
		}
	}
	if(c<=m){
		cout << 1<<" "<<c;
		return 0;
	}
	b=(c+n-1)/n;
	if(b%2==1){
		if(c%n==0){
			cout << b<< " "<< n;
			return 0;
		} 
		cout << b<<" "<< c%n;
	}else{
		if(c%b==0){
			cout << b<< " "<<1;
			return 0;
		}
		cout << b<<" "<< c-(b-1)*n; 
	}
	return 0;
}
