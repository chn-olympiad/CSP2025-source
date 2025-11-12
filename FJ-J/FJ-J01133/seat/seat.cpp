#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[105],ps=1;
int cmp(int op1,int op2){
	return op1>op2;
}
int xiaoR;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xiaoR=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(a[ps++]==xiaoR){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				if(a[ps++]==xiaoR){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Âå¹È£ºQoQ_ 
*/
