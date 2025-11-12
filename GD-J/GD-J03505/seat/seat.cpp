#include<bits/stdc++.h>
using namespace std;
int m,n,x,large;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	cin>>x;
	for(int i=2;i<=n*m;i++){
		int e;
		cin>>e;
		if(e>x) large++;
	}
	int li=large/n+1;
	int yu=large%n+1;
	if(li%2==0){
		yu=(n-yu+1);
	}
	cout<<li<<" "<<yu;
	return 0;
} 
