#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[205];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	int sum=0;
	bool f=0;
	for(int i=1;i<=n*m;i++){
		f=0;
		cin>>a[i];
		if(a[i]==i){
			f=1;
		}
		if(a[i]==n*m-i+1){
			f=0;
		}
	}
	if(f==1){
		cout<<m<<" "<<n;
	}else{
		cout<<"1 1";
	}
	return 0;
}
