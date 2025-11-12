#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int num=1;
	for(int i=1;i<n*m;i++){
		if(a[0]<a[i]){
			num++;
		}
	}
	if(num<=m){
		cout<<1<<" "<<m;
	}else if(num%m==0){
		cout<<num/m+1<<" "<<1;
	}
	else if(num/m%2==0){
		cout<<num/m+1<<" "<<num%m;
	}else if(num/m%2==1){
		cout<<num/m+1<<" "<<abs(num%m-n)+1;
	}
	return 0;
}