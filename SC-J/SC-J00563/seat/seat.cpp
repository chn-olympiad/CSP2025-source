#include <bits/stdc++.h>
using namespace std;
int n,m,k,r,a[110],q;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<k;i++){
		if(a[i]==r){
			if(i%n==0){
				m=i/n;
				if(m%2==0){
					cout<<m<<" "<<1;
					return 0;
				}
				if(m%2!=0){
					cout<<m<<" "<<n;
					return 0;
				}
			}
			else{
				m=i/n+1;
				if((m-1)%2==0){
					cout<<m<<" "<<i%n;
					return 0;
				}
				if((m-1)%2!=0){
					cout<<m<<" "<<n-(i%n-1);
					return 0;
				}
			}
		}
	}
	return 0;
}