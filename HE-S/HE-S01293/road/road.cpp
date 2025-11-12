#include<bits/stdc++.h>
using namespace std;
int a[100000],b[100000],c[100000];
void st(int x){
	if(x>=10)return ;
	for(int i=1;i<=10;i++){
		cout<<i<<" ";
		st(x+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	st(1);
	fclose(stdin);
	fclose(stdout);
	 
}
	

