#include<bits/stdc++.h>
using namespace std;
int TF(int a,int b){
	if((a/b)==(a*1.0/b)) return 1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cj[110],c,r,d;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>cj[i];
	}
	int a=cj[1];
	for(int i=n*m;i>1;i--){
		for(int j=1;j<i;j++){
			if(cj[j]<cj[j+1]){
				swap(cj[j],cj[j+1]);
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(cj[i]==a) d=i;
	}
	if(((d/m+1)%2==0)||(TF(d,m)==1)){
		if((d/m)<(d*1.0/m)) c=d/m+1;
		else c=d/m;
		if(n-d%n!=n) r=n-d%n+1;
		else r=n-d%n;
	}
	else{
		if((d/m)<(d*1.0/m)) c=d/m+1;
		else c=d/m;
		r=d%n;
	}
	cout<<c<<' '<<r; 
	cout<<endl<<d/m<<' '<<d*1.0/m<<' '<<d;
	return 0;
}
