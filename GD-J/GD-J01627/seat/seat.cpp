#include<bits/stdc++.h>
using namespace std;
bool cpd(int a,int b){
	return a>=b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int x[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>x[i];
	int c=x[1];
	sort(x+1,x+(n*m)+1,cpd);
	int id;
	for(int i=1;i<=n*m;i++){
		if(x[i]==c) id=i;
	} 
	int y=id/n,z=id%n;
	if(z==0){
		cout<<y<<" ";
		if(y%2==0) cout<<1;
		else cout<<n;
	}else{
		cout<<y+1<<" ";
		if(y%2==0) cout<<z;
		else cout<<n-z+1;
	}
	return 0;
} 
