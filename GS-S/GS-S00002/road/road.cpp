#include<bits/stdc++.h>
using namespace std;

int n,m,k,ans;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	int a,b,d;
    	cin>>a>>b>>d;
    	ans+=d;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int t;
			cin>>t;
		}
	}
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
