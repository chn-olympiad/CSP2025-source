#include<bits/stdc++.h>
using namespace std;
int n,i,j,m,jl,y;
int a[11][11];
int temp[101];
bool end1=false;
bool tj(int a,int b){
	return a>b;
}
void f(){
	for(i=n-1;i>=0;i--){
		if(temp[y]==jl){
			cout<<j+1<<" "<<i+1<<endl;
			end1=true;
			return;
		}
		a[i][j]=temp[y--];
		if(i==0) j++;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	y=n*m-1;
	for(int z=0;z<n*m;z++){	
		cin>>temp[z];
		if(z==0) jl=temp[z];
	}
	sort(temp,temp+(n*m));
	
	for(i=0;i<n;i++){
		
		if(temp[y]==jl){
			cout<<j+1<<" "<<i+1<<endl;
			return 0;
		}
		a[i][j]=temp[y--];
		if(i==n-1){
			j++;
			f();
			if(end1) return 0;
		}
	}
	return 0;
} 
