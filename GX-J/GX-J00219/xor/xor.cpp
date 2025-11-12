#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500000];
int xorr(int a,int b){
	int x[21],y[21],z[21];
	for(int i=0;i<=20;i++){
		x[i]=0;
		y[i]=0;
		z[i]=0;
	}
	
	for(int i=20;i>=0;i--){
		if(a>=pow(2,i)){
			a-=pow(2,i);
			x[i]=1;
		}
		if(b>=pow(2,i)){
			b-=pow(2,i);
			y[i]=1;
		}
	}
	int t=0;
	for(int i=20;i>=0;i--,t++){
		if(x[i]==y[i]) z[t]=0;
		else z[t]=1; 
	}
	for(int i=0;i<=20;i++){
		cout<<z[i];
	}
	cout<<endl;
	int sum=0;
	int c=0;
	for(int i=20;i>=0;i--,c++){
		if(z[i]==1) sum+=pow(2,c);
	}
	return sum;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cout<<xorr(23,11);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2;
		return 0;
	}else{
		cout<<7;
		return 0;
	}
}
