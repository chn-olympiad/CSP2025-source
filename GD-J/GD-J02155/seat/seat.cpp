#include<bits/stdc++.h>
using namespace std;
int n,m,p[105],ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>p[1];
	for(int i=2;i<=n*m;i++){
		cin>>p[i];
		if(p[1]<p[i]) ans++;
	}cout<<ans/m+1<<' ';
	if((ans/m)%2==0){
		cout<<m-ans%m;
	}else {
		cout<<ans%m+1;
	}
	
}
