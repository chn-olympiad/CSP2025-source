#include<bits/stdc++.h>
using namespace std;
int s[10001][10001];
int c[11],z[10005][11];
int ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,b=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		cin>>s[a][b];
		if(k=0) ans+=s[a][b];
		s[b][a]=s[b][a];
		s[b][b]=0;s[a][a]=0;
	}
	if(k==0){
		cout<<ans;	
	}else{
		bool flag=1;
		for(int i=1;i<=k;i++){
			cin>>c[i];
			if(c[i]!=0) flag=0;
			for(int j=1;j<=n;j++){
				cin>>z[j][i];
				if(z[j][i]!=0) flag=0;
			}
		}
		if(flag) ans=0;
		else{
			for(int i=1;i<=k;i++){				
				for(int j=1;j<=n;j++){
					for(int p=1;p<=n;p++){
						s[j][p]=min((c[k]+z[j][i]+z[p][i]),s[j][p]);
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans+=s[i][j];
		}
	}
	ans/=2;
	cout<<ans;
	return 0;
}