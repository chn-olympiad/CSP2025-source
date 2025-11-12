#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	int num=n*m;
	int cj[num];
	int tidai=0;
	cin>>cj[0];
	int pm=1;
	for(int i=1;i<num;i++){
		cin>>cj[num];
		if(cj[num]>cj[0]){
			pm++;
		}
	}
	int c=0;
	if(pm<=n){
		c=1;	
	}
	else{
		c=pm/n+1;
	}
	printf("%d",c);
	cout<<" ";
	int r=0;
	int jl=0;
	if(c==1){
		jl=pm;
	}
	else{
		if(pm>n&&pm<c*n){
			jl=pm%(n*(c-1));
		} 
		else{
			jl=pm%(n*c);
		}		
	}
	if(c%2==0){
		r=n+1-jl;
	}
	else{
		r=jl;	
	}
	printf("%d",r);
} 
