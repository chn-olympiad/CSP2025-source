#include<bits/stdc++.h>
using namespace std;
bool cmd(int a,int b){
	if(a>=b) return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[110];
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	int a0=a[0];
	int g=0;
	sort(a,a+n*m,cmd);
	for(int i=0;i<m*n;i++){
		if(a[i]==a0){
			g=i+1;
			break;
		}
	}
	int h,l;
	if(g%m==0) l=g/m;
	else l=g/m+1;
	cout<<l<<" ";
	if(g%m==0){
		if(l%2==0) l=1;
		else l=n;
	}
	else if(l%2==1) h=n-(l*m-g);
	else h=l*m-g+1;
	cout<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
