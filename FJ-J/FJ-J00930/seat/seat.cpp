#include <bits/stdc++.h>

using namespace std;
const int N=1000;
int n,m,cl,ljr;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cl=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cl){
			ljr=i;
		}
	}
	int lyp,cyc;
	double ll=ljr;
	double wy=ll/n*1.0;
	if(ljr%n==0){
		lyp=n;
		
	}else{
		lyp=ljr%n;
	}
	if(wy<=1){
		cyc=1;
	}else{
		cyc=ljr/n+1;
	}
	if(cyc%2==0){
		cout<<cyc<<" "<<n+1-lyp;
	}else{
		cout<<cyc<<" "<<lyp;
	}
	return 0;
}




