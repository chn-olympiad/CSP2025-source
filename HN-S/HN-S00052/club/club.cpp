#include<bits/stdc++.h>
using namespace std;
int n,t,sc;
long long a[100005][5],f[100005][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ta=0,tb=0,tc=0;
		int ans = 0;
		cin>>n;
		sc=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){;
			int maxt = 0,y;
			for(int j=1;j<=3;j++){
				if(a[i][j]>maxt){
					maxt=a[i][j];
					y=j;
				}
			}
			if(y==1) ta++;
			else if(y==2) tb++;
			else tc++;
			ans+=maxt;
		}
		if(ta>sc || tb>sc || tc>sc){
			cout<<ans-sc<<endl;
		}
		else{
			cout<<ans<<endl;
		}
	}
	return 0;
}

