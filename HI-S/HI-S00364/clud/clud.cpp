#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,sum;
int main(){
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>x>>y>>z;
			x=max(x,y);
			z=max(x,z);
			sum+=z;
		}
	}
	cout<<sum;
	return 0;
}

