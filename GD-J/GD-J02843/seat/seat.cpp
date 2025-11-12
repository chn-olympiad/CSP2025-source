#include<bits/stdc++.h>
using namespace std;
int n,m,fs[105],R,zw[15][15],wz,yc;
int compare(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a;
	for(int i=1;i<=n*m;i++){
		cin>>fs[i];
		a++;
	}
	R=fs[1];
	sort(fs+1,fs+a+1,compare);
	for(int i=1;i<=a;i++){
		if(fs[i]>=R&&fs[i+1]<R&&fs[i-1]>R){
			wz=i;
			break;
		}
	}
	cout<<wz;
	yc=ceil(1.00*wz/n);
	if(wz<=m){
		cout<<"1"<<" ";
	}
	else{
		cout<<ceil(1.00*wz/n)<<" ";
	}
	
	if(wz<=n){
		cout<<wz<<" ";
	}
	else if(yc%2==0){
		cout<<n+1-wz%n<<" ";
	}
	else{
		cout<<wz%n<<" ";
	}
	return 0;
}
