#include<bits/stdc++.h>
using namespace std;
int t,maxx=-1,q=50000,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int m3[n][3];
		for(int j=0;j<n;j++) cin>>m3[j][0]>>m3[j][1]>>m3[j][2];
		while(q--){
			for(int x=0;x<n;x++){
				maxx=max(m3[x][0],maxx);
			}
			ans+=maxx;
			int maxx=0;
			
			
		}
		
	}
	cout<<ans;
	return 0;
}
