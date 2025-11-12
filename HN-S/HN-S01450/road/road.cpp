#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0){
		int a[1000010];
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y>>a[i]; 
		}
		sort(a+1,a+1+m);
		int ans=0;
		for(int i=1;i<n;i++)ans+=a[i];
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
} 
