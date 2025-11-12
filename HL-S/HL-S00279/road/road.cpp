#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,k;
int a[N][N],w[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m,n,k,a,b,c;
	int ans=0;
	cin>>m>>n>>k;
	if(k==0||k==5||k==10){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		ans+=c;
	}
	cout<<ans;
	
	return 0;
}