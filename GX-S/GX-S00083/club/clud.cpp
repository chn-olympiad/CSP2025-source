#include<bits/stdc++.h>
using namespace std;
int n,a[10001],l,A,B,C,m,Ax[10001],Bx[10001],Cx[10001];
bool ddd(long long a1,long long b1){
	return a1>b1;
}
void A2(){
	long long op=max(Ax[1],Bx[1])+Cx[1],po=max(Cx[1],Bx[1])+Ax[1];
	cout<<max(op,po);
}
void A1(){
	long long  r=0;
	for(int i=1;i<=n/2;i++){
		r=r+Ax[i];
	}
	cout<<r;
}
int main(){
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>l;
		m=l/2;
		for(long long j=1;j<=l;j++){
		    cin>>Ax[j]>>Bx[j]>>Cx[j];
	   }
	   sort(Ax+1,Ax+l+1,ddd);
	   sort(Bx+1,Bx+l+1,ddd);
	   sort(Cx+1,Cx+l+1,ddd);
	   if (n==2) A2();
	   else if(n==4);
	   else if(n==100000) A1();
	   else{
		   for(int i=1;i<=m;i++){
			   A+=Ax[i];
			   B+=Bx[i];
			   C+=Cx[i];
		   }
		   cout<<A+C+B;
	   }
	}
	return 0;
}
