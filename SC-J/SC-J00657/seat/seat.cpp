#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w=1;
	std::cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		std::cin>>a[i];
		if(i!=1&&a[i]>a[1]) w++;
	}
	int x=1,y=0,i=1;
	while(w--){
		y+=i;
		if(y==n&&x%2!=0){
		x++;i=-1;w--;}
		if(y==1&&x%2==0){
		x++;i=1;w--;}
	}
	std::cout<<x<<" "<<y;
	return 0;
} 