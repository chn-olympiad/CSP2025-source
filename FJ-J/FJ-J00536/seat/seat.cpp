#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,sum=1;
	cin>>n>>m;
	cin>>s;
	for(int i=2;i<=n*m;i++){
		int t;
		cin>>t;
		if(t>s){
			sum+=1;
		}
	}
	int a=sum%(n*2),b=sum/(n*2);
	if(a==0){
		cout<<2*b<<' '<<1;
	}else if(a<=n){
		cout<<2*b+1<<' '<<a;
	}else{
		cout<<2*b+2<<' '<<2*n-a+1;
	}
	return 0;
}
