#include<bits/stdc++.h>
using namespace std;
int a[1000];
int n,k;
int sum;
int b(int z){
	int sum1=0;
	int x,y;
	x=a[0];
	y=a[z];
	for(int i=1;i<z;i++){	
		x=x^a[i];
		cout<<x<<" ";
	}
	for(int j=z+1;j<n;j++){	
		y=y^a[j];
		cout<<y<<" ";
	

	}
	if(x==k){
		sum1++;
	}
	if(y==k){
		sum1++;
	}
	cout<<x<<y<<endl;
	return sum1;
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;

	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		sum+=b(i);
		
	}
	
	cout<<sum;
}

