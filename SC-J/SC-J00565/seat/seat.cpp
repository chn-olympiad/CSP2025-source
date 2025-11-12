#include<bits/stdc++.h>
using namespace std;
const long long T=11;
int b[T*T];//列，行 
int n,m,r;//n行m列 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;//总座位 
	for(int i=1;i<=k;i++){
		cin>>b[i];
	}
	r=b[1];
	sort(b,b+k+1);
	int top;
	for(int i=k;i>0;i--){
		if(b[i]==r) top=k+1-i;
	}
	double y=top/n;
	if(y>top/n) y++;
	int x=y;
	if(x%2==0){
		cout<<x<<" "<<top%(2*n);
	}else{
		cout<<x<<" "<<n-top%n;
	}	
	return 0;
} 