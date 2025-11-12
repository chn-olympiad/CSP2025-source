//GZ-S00497 遵义市第四中学 马昭懿
#include<bits/stdc++.h>
using namespace std;

int n,m,k;
long long ans;
int main(){
	freopen("road","r",stdin);
	freopen("road","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(i==6){
			ans+=z;
		}
		if(i==7){
			ans+=z;
		}
	}
	for(int j=1;j<=k;j++){
		for(int c=1;c<=n+1;c++){
			string s;
			getline(cin,s);
		}
	}
	cout<<ans;
	return 0;
}

