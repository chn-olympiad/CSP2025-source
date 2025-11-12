#include<bits/stdc++.h>
using namespace std;
int n,m,c[110],a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	int x=c[1],p;
	sort(c+1,c+m*n+1);
	for(int i=m*n;i>=1;i--) {
		a[m*n-i+1]=c[i];
		if(c[i]==x) p=m*n-i+1; 
	}
	cout<<x<<" "<<p<<endl;
	int c=p/n,r;//c向上取整 
	if(double(p)/n>double(c)) c++;  
	if(c%2==0){
		r=n-p%n+1;
	}else{
		r=p%n;
	}
	if(r==0) r=n;
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}