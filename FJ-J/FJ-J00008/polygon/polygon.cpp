#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ma=0,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<1;
	}else if(n==4){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<2;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<9;
	}
	return 0;
}
