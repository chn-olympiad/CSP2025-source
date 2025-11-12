#include <bits/stdc++.h>
using namespace std;
int b[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p=0,t;
	cin>>t;
	b[0]=t;
	for(int i=1;i<n*m;i++){
		cin>>b[i];
		if(b[i]>t){
			p++;
		}
	}
	int x=0,y=0;
	if((p/n)%2==0){
		x=p%n+1;
		y=p/n+1;
	}else{
		x=n-p/n+1;
		y=p/n+1;
	}
	cout<<y<<" "<<x<<endl;
	return 0;
} 
