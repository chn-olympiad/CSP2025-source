#include<bits/stdc++.h>
using namespace std;
int n,m,a,b[100005],ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<n*m-1;i++){
		cin>>b[i];
	}b[n*m-1]=a;
	
	sort(b,b+n*m);
	for(int i=0;i<n*m/2;i++){
		int c=b[i];
		b[i]=b[n*m-i-1];
		b[n*m-i-1]=c;
		
	}
	for(int i=0;i<n*m;i++){
		if(b[i]==a){
			ans=i+1;
		}
	}int d;
	if(ans%n!=0){
		d=ans/n+1;
	}else{
		d=ans/n;
	}
	cout<<d<<endl;
	if(d%2==1){
		cout<<ans%(2*n);
	}else{
		cout<<(n*m-ans)%n+1;
	}


	return 0;
}
