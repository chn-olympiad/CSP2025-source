#include<bits/stdc++.h>
using namespace std;
int n,m,x,s;
int a[110],b[110];
int main(){
	freopen("seat.in","r",stdin);	
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	x=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}sort(a,a+n*m);
	s=n*m-1;
	for(int i=0;i<n*m;i++){
		b[s]=a[i];s--;
	}
	for(int i=0;i<n*m;i++){
		if(b[i]==x) x=i;
	}if(x<n){
		cout<<1<<" "<<x+1;
		return 0;
	}
	cout<<x/n+1<<" ";//m
	if((x/n+1)%2!=0){			//n
		cout<<(x+1)%n;
	}else{
		cout<<((x/n+1)*n-1)/n;
	}
	
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}
