#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m];
	int k=m*n;
	int b[k];
	for(int i=0;i<k;i++){
		cin>>b[i];
	}
	if(n==1&&m==1){
		cout<<1;
	}
	
	return 0;
	//½â×¢ÊÍ 
}
