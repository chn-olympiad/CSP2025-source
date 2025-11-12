#include<bits/stdc++.h>
using namespace std;
long long n,m,r,wz,x,y;
long long f[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>f[i];
	}
	r=f[0];
	sort(f,f+n*m);
	for(int i=0;i<=n*m;i++){
		if(r==f[i]){
			wz=n*m-i;
		}
	}
	x=wz/(n+1)+1;
	if(x%2==0){
		y=n+1-(wz-(x-1)*n);
	}
	else{
		y=wz-(x-1)*n;
	}
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
