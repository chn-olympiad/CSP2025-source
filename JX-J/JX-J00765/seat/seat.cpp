#include<bits/stdc++.h>
using namespace std;
long long n,m,a[15][15],nm[200],w;
int main(){
	cin>>n>>m;
	long long t=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			nm[t]=a[i][j];
			t++;
		}
	}
	long long r=nm[0];
	sort(nm,nm+n*m);
	for(int i=1;i<=n*m;i++){
		if(r==nm[i]){
			w=n*m+1-i;
		}
	}
	long long J=((w/(n*2))*2),I=(w%(n*2));
	if(I==0){
		I=1;
		
	}
	else{
		if(I>n){
			I-=n;
			I=n-I+1;
			J+=2;
		}
		else{
			J++;
		}
	}
	
	cout<<(5000*4999)*(4998/6);
	return 0;
}
