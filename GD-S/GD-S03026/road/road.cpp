#include<bits/stdc++.h>
using namespace std;
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		ans+=c;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
