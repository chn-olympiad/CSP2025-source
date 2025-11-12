#include<bits/stdc++.h>
using namespace std;
bool a(int a,int b){
	return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n[11][11],m[110],c,k,x,cc=1,kk=1;
	cin>>c>>k;
	for(int i=1;i<=c*k;i++)
		cin>>m[i];
		x=m[1];
	sort(m+1,m+c*k+1,a);
	for(int i=1;i<=c*k;i++){
		if(x==m[i])
		cout<<kk<<' '<<cc;
		if(cc==c&&kk%2==1||cc==1&&kk%2==0){
			kk++;
			continue;}
		if(cc!=c&&kk%2==1)
			cc++;
		if(cc!=1&&kk%2==0)
			cc--;}
	return 0;}