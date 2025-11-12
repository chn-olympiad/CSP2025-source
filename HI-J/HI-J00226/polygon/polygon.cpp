#include<bits/stdc++.h>
using namespace std;
int p[5009];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s=0,all=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		all+=p[i];
		s=max(p[i-1],p[i]);
	}
	if(all>s*2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}

