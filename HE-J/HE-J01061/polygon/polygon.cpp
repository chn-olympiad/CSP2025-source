#include<bits/stdc++.h>
using namespace std;
int b[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>b[i];
	}
	int mx=-1;
	if(n<3){
		cout<<0;
		return 0;
	}
	
	else if(n==3){
		mx=max(max(max(mx,b[1]),b[2]),b[3]);
		if(mx<b[1]+b[2]+b[3]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
