#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	int a,b,d,m,r;
	cin>>a>>b;
	d=a*b;
	int c[d];
	for(int i=0;i<d;i++){
			cin>>c[i];}
	m=c[0];
	for(int i=0;i<d;i++){
		for(int j=i+1;j<d;j++){
			if(c[i]<c[j]){
				r=c[i];
				c[i]=c[j];
				c[j]=r;}}
		cout<<c[i]<<" ";}
	for(int i=0;i<d;i++){
		if(m==c[i]){
			r=i+1;}}
	if(r%2==1){
		cout<<r/2+1<<" "<<r%b;}
	else{
		cout<<r/2<<" "<<b-r%b;}
	return 0;
}
