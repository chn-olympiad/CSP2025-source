#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],r,ri;
bool c(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	r=a[0];
	sort(a+0,a+n*m,c);
	for(int i=0;i<n*m;i++){
		if(a[i]==r) ri=i+1;
	}
	
	int x,y;
	x=ri/n+1;
	if(x%2==0) y=n-ri%n+1;
	else y=ri%n;
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

