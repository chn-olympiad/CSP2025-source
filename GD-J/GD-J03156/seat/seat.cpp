#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool bol(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1],zzc=0;
	sort(a+1,a+n*m+1,bol);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			zzc=i;
		}
	}
	int zhx=0;
	if(zzc%n==0){
		zhx=zzc/n;
	}
	else{
		zhx=zzc/n+1;
	}
	if(zhx%2!=0){
		if(zzc%n!=0){
			cout<<zhx<<" "<<zzc%n;
		}
		else{
			cout<<zhx<<" "<<n;
		}
	}
	else{
		cout<<zhx<<" "<<zhx*2+1-zzc;
	}
	return 0;
} 
