#include<bits/stdc++.h>
using namespace std;
int a[105]; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;//行数，列数 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		 cin>>a[i];
	} 
	int p=100-a[1]+1;//排名 
	cout<<1<<p; 
	return 0;
} 
