#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	int n,m,a[100],x;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	x=a[0];
	for(int i=0;i<n*m;i++){
			for(int j=0;j<i;j++){
				if(a[i]>a[j]){
					swap(a[i],a[j]);
				}
			}
			}
			int z=0;
	for(int i=0;i<m;i++){
		if(i%2==1){
			for(int j=0;j<n;j++){
				z++;
			if(x==a[z]){
					cout<<i+1<<" "<<j+1;
					return 0; 
				}
		}
	}else{
		for(int j=n-1;j>=0;j--){
				if(x==a[z]){
					cout<<i+1<<" "<<j+1; 
					return 0;
				}
	}
}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
