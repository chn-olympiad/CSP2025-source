#include<bits/stdc++.h>
using namespace std;
long long a[100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long sum=0;
	long long b=n*m;
	for(long long i=1;i<=b;i++){
		cin>>a[i];
		if(i==1)
		sum=a[i];
	}
	sort(a+1,a+b+1,cmp);
	for(int i=1;i<=b;i++){
		if(a[i]==sum){
			if(i<=n){
			cout<<"1";
			}else if(i>n){
				if(i%n==0){
				cout<<i/n;
				}else{
				cout<<i/n+1;
				}
			}
		}
	}
	for(long long i=1;i<=b;i++){
		if(a[i]==sum){
			if(i<=m){
				if(m==i){
				cout<<" "<<m;	
				}else{
				cout<<" "<<m%i;
				}
			}else if(i>m){
				if(i%m==0){
					if((i/m)%2==0){
						cout<<" "<<"1";
					}else{
						cout<<" "<<m;
					}
				}else if((i/m+1)%2==0){
					cout<<" "<<i%m+m-i%m;
				}else{
					cout<<" "<<i%m;
				}
			}
		}
	}
	return 0;
}
