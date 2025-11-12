#include<bits/stdc++.h>
using namespace  std;
int n,j,m,ans;
int mian(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cout<<m;
	int s[n+1][4],v[n+1];
	while(m--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j=3;j++){
				cout<<s[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			v[i]=max(s[i][1],max(s[i][2],s[i][3]));
			for(int j=1;j<=3;j++){
				if(s[i][j]==v[i]){
					v[i]=j;
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans+=s[i][v[i]];
		}
		cout<<ans;
	}
	
	
	
	return 0; 
}
