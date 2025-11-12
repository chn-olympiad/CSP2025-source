#include<bits/stdc++.h>
using namespace std;
int main() {
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	int n,m,c=1,r=1,cr,cc=0,a=0;
	cin>>n>>m;
	cin>>cr;
	int aa[n*m-1];
	for(int i=0;i<n*m-1;i++){
		cin>>aa[i];
	}
	for(int j=0;j<n*m-1;j++){
	
	for(int i=0;i<n*m-1;i++){
		if(aa[i]<aa[i+1]){
			cc=aa[i];
			aa[i]=aa[i+1];
			aa[i+1]=cc;
		}
	}
}
	for(int i=0;i<n*m-1;i++){
		
				
		if(cr<aa[i] && a==0)r+=1;
		if(cr<aa[i] && a==1)r-=1;
		if(c%2==0){
			a=0;
	} else{
		a=1;}
		if(r==n||r==1)c+=1;	
		if(cr>aa[i])break;

}
	cout<<c<<" "<<r+1;
	
fclose(stdin);
fclose(stdout);
	return 0;
}
