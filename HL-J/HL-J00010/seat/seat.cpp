#include<bits/stdc++.h>
using namespace std;
int t=0;
int hang=0;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int map[n][m];
	int ren=n*m;
	int a[ren];
	for(int i=1;i<=ren;i++){
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+ren+1,greater<int>());
	for(int i=1;i<=ren;i++){
		if(a[i]==num){
			t=i;
		}
	}
	if(m%2==0){
		int zhouqi=n*2;
		if(t>zhouqi){
			t%=zhouqi;
			if(t>n){
				hang=n-(t-n)+1;
				cout<<(ren-t)/m<<" "<<hang;
			}
			else {
				hang=t;
				cout<<(ren-t)/m<<" "<<hang;
			}
		}
		else if(t<=zhouqi){
			if(t>n){
				hang=n-(t-n)+1;
				cout<<2<<" "<<hang;
			}
			else {
				hang=t;
				cout<<1<<" "<<hang;
			}
		}
	}
	else{
		int zhouqi2=n*2;
		if(t>=zhouqi2){
			if(t>n){
				hang=t-zhouqi2;
			}
			else hang=t-zhouqi2;
		}
		else if(t<=zhouqi2){
			if(t>n){
				hang=t-n;
			}
			else hang=t;
		}
		if(t<=n){
			cout<<1<<" "<<hang;
		}
		else cout<<t/m+1<<" "<<hang;	
	}
	return 0;
}
