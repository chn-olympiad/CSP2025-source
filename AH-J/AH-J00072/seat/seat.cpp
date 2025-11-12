#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int R=0,nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+nm+1,cmp);
	if(m%2==0 && R==a[nm]){
		cout<<m<<" "<<1;
		return 0;
	}else if(m%2==1 && R==a[nm]){
		cout<<m<<" "<<n;
		return 0;
	}else if(m%2==0 && R==a[nm-1]){
		cout<<m<<" "<<n;
		return 0;
	}else if(m%2==1 && R==a[nm-1]){
		cout<<m<<" "<<n-1;
		return 0;
	}else if(m%2==0 && R==a[nm-2]){
		if(n>2){
			cout<<m<<" "<<3;
			return 0;
		}else{
			cout<<m-1<<" "<<n;
			return 0;
		}
		
	}else if(m%2==1 && R==a[nm-2]){
		if(n>2){
			cout<<m<<" "<<n-2;
			return 0;
		}else{
			cout<<m-1<<" "<<1;
			return 0;
		}
	}		
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(R==a[i]){
				cout<<j<<" "<<i;
				return 0;
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==0){
				if(R==a[j]){
					cout<<i<<" "<<(j+n)%n;
					return 0;
				}
			}else{
				if(R==a[j]){
					cout<<i<<" "<<j;
					return 0;
				}
			}
			
		}
	}
	return 0;
}
