#include <bits/stdc++.h>
using namespace std;
bool f(int x,int y){
	return x>=y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m]={};
	for(int i=0;i<n*m;i++){
		cin>>a[i];	
	}
	int z=a[0];
	int z1,z2=1;
	sort(a,a+n*m,f);
	for(int i=0;i<n*m;i++){
		if(a[i]==z){
			z1=i+1;
			break;
			}
		}
	int f1=0,m1=1,n1=1;
	while(z2==z1){
		if(f1==0){
			n1++;
			}
		if(f1==1){
			n1--;}	
		z2++;
		if(n1==n){
			f1=1;
			m1++;
			z2++;}
		if(n1==1){
			f1=0;
			m1++;
			z2++;
			}
		}
	cout<<n1<<' '<<m1;
	return 0;
	}
