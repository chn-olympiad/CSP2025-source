#include<bits/stdc++.h>
using namespace std;
int n,m,s=0;
int a[1000001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[1]>a[i+1]){
			cout<<"1 1";
		}
		else{
			sort(a,a+n+1);
			if(s==n){
				cout<<n<<" "<<m;
			}
		}
	}
	
	return 0;
	}
