#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int m,n,csp_test[121],r_test,r,x,y;
bool flag=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<n*m;i++){
		cin>>csp_test[i];
		r_test=csp_test[0];
	}
	sort(csp_test,csp_test+n*m-1,cmp);
	for(int i=0;i<n*m;i++){
		if(r_test==csp_test[i])r=i+1;
	}
	cout<<r<<" ";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			r=r-1;
			if(r==0){
				flag=1;
				x=j+1;
				
				break;
			}
		}
		if(flag==1){
			y=i+1; 
			break;
		}
	}
	if(y%2==1)cout<<y<<" "<<x;
	if(y%2==0)cout<<n-x<<" "<<y;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
