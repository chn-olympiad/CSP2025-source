#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100],exam;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n*m;i++){
		cin>>a[i];
	}
	exam=a[0];
	sort(a,a+n*m,cmp);
	for(long long i=0;i<n*m;i++){
		if(exam==a[i]){
			if((i+1)%m==0){
				cout<<(i+1)/m;
			}
			else{
				cout<<(i+1)/m+1;
			}
			cout<<' ';
			if(i/n%2==0){
				if((i+1)%n==0){
					cout<<n;
				}
				else{
					cout<<(i+1)%n;
				}
			}
			else{
				if((i+1)%n==0){
					cout<<1;
				}
				else{
					cout<<n-(i+1)%n+1;
				}
			}
		}
	}
	return 0;
}
