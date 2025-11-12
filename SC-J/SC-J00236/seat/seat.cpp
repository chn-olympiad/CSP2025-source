#include<bits/stdc++.h>
using namespace std;
int cj; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=n*m;
	int k=2*n; 
	int R;//小R的成绩 
	cin>>R;
	int sum=1;//小R的位次 
	for(int i=1;i<=s-1;i++){
		cin>>cj;
		if(cj>R){
			sum++;
		} 
	}
	int a=sum%(n*2);
	int b=sum/(n*2);
	if(a>n){
		cout<<b*2+2<<" "<<2*n-a+1;
	}else if(a==n){
		cout<<b*2+1<<" "<<n;
	}else if(a!=0){
		cout<<b*2+1<<" "<<a;
	}else if(a==0){
		cout<<b*2<<" "<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}