#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100010][3];
priority_queue <pair<int,int> ,vector <pair<int,int>>,greater<pair<int,int>>> q[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		for(int j=0;j<3;j++){
			if(!q[j].empty()) q[j].pop();
		}
		for(int i=1;i<=n;i++){
			int mxn=0;
			for(int j=0;j<3;j++){
				mxn=max(mxn,a[i][j]);
			}
			for(int j=0;j<3;j++){
				if(mxn==a[i][j]){
					int mx=0;
					for(int k=0;k<3;k++){
						if(k==j) continue;
						mx=max(mx,a[i][k]);
					}
					q[j].push({mxn-mx,i});
					if(q[j].size()>(n/2)){
						int id=q[j].top().second;
						q[j].pop();	
						int mxn=0;
						for(int k=0;k<3;k++){
							if(k==j) continue;
							mxn=max(mxn,a[id][k]);
						}
						for(int k=0;k<3;k++){
							if(k==j) continue;
							if(a[id][k]==mxn){
								q[k].push({1e9,id});
								break;
							}
						}
					} 
					break;
				}
			}
		}
		int ans=0;
		for(int i=0;i<3;i++){
			while(!q[i].empty()){
				int id=q[i].top().second;
				ans+=a[id][i];
				q[i].pop();
			}
		}
		cout<<ans<<endl; 
	}
	
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
