#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[166];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int sum=1;
	for(int i=2;i<=m*n;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			sum++;
		}
	}
	int ansh,ansl;
	ansl=(sum-1)/n+1;
	if(ansl%2==1){
		ansh=sum%n;
		if(ansh==0){
			ansh=n;
		}
	}else{
		ansh=n-sum%n+1;
		if(ansh==n+1){
			ansh=1;
		}
	}
	cout<<ansl<<' '<<ansh;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 