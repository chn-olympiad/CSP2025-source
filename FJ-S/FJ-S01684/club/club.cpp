#include<bits/stdc++.h>
using namespace std;
int Main(){
	int n,t,x,y,z;
	cin>>n;
	while(n--){
		cin>>x>>y>>z;
		t+=max(x,max(y,z));
	}
	cout<<t<<'\n';
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--)Main();
	return 0;
}
