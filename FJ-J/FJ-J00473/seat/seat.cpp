#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	int n,m,a[105],b=0,c=1;
	cin>>n>>m;

	
	b=a[0];a[0]=0;
	int max=-1e+9;
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]>b){
		c++;
			
		}
			
		
	}
	if(c<=n){
		cout<<1<<' '<<c;
		return 0;
}	if(c>=n&&c<=2*n){
		cout<<2<<' '<<c-1;
}if(c>=2*n&&c<=3*n){
		cout<<3<<' '<<c-6;
}

	return 0;
}