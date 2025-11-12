#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen('seat.in','r',stdin);
	freopen('seat.out','w',stdout);
	int n,m;
	cin>>n>>m;
	long long R,r;
	int sc[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>sc[i];
	}
	R=sc[1];
	for(int i=1;i<=n*m-1;i++){
		for(int j=1;j<=n*m-1;j++){
			if(sc[j]<sc[j+1]){
				int b=sc[j];
				sc[j]=sc[j+1];
				sc[j+1]=b;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(sc[i]==R){
			r=i;
			break;
		}
	}
	int x,x1;
	x=r%n;
	x1=r/n;
	if(r%n!=0){
		int y=(r/n)+1;
		cout<<(r/n)+1<<" ";
		if(y%2==0){
			cout<<n+1-x;
		}
		else{
			cout<<x;
		}
		return 0;
	}
	else{
		cout<<r/n<<" ";
		int y=r/n;
		if(y%2==0){
			cout<<"1";
		}
		else{
			cout<<n;
		}
		return 0;
	}
	return 0;
} 
