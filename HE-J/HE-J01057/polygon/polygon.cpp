#include<bits/stdc++.h>
using namespace std;
const int N=5*1e3+10;
int n,ans,a[N],sm;
int main(){
	cin>>n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sm+=a[i];
		a[i]*=2;
	}
	for(int i=1;i<=n;i++){
		if(a[i]>=sm){
			cout<<0;
			return 0;
		}
	}
	cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
