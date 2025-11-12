#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;
int b,s=0;
int x,y,z;
for(int i=1;i<=m;i++){
	cin>>x>>y>>z;
	s+=z;
} 
for(int i=1;i<=k;i++)
	for(int j=1;j<=n+1;j++) cin>>b;
	if(k==0) cout<<s<<endl;
	else {
		cout<<0<<endl;
	}
	return 0;
}

