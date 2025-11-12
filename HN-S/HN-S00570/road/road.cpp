#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,a,ans=0;
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++){
		int b,c,d;
		cin>>b>>c>>d;
		ans+=d;
	}for(int i=1;i<=(m+1)*2;i++){
		int b;
		cin>>b;
	}cout<<ans;
	return 0;
}


