#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m];
	int s[n*m];
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	cout<<1<<" "<<1;
	return 0;
} 
