#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
bool cmd(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,h;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	
	cout<<rand()%m+1<<" "<<rand()%n+1;
	return 0;
}