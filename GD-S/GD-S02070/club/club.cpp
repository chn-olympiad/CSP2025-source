#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,m[N][3];
bool f[N][3];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i][0]>>m[i][1]>>m[i][2];
		} 
		for(int i=1;i<=n;i++){
			int x=0,y=0;
			for(int j=0;j<3;j++){
				if(y<m[i][j]){
					y=m[i][j],x=j;
				}
			}	
			q[x].push({y,i});
			f[i][x]=true;
			if(q[x].size()>n/2){
				pair<int,int> a;
				a=q[x].top();
				q[x].pop();
				int c=0,b=0;
				for(int j=0;j<3;j++){
					if(y<m[a.second][j]&&!f[a.second][j]){
						c=j,b=m[a.second][j];
					}
				}
				q[c].push({b,a.second});
			}
		}
		for(int i=0;i<3;i++){
			while(q[i].size()){
				ans+=q[i].top().first;
				q[i].pop();
			} 
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//const int N=210,M=N/2;
//int t,n,m[N][4];
//int f[N][M];
//int main(){
////	freopen("club.in","r",stdin);
////	freopen("club.out","w",stdout);
//	cin>>t;
//	while(t--){
//		int ans=0;
//		cin>>n;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cin>>m[i][j];
//			}
//		} 
//		for(int i=1;i<=n;i++){
//			for(int k=1;k<=n/2;k++){
//				
//			}
//		}
//	}
//	return 0;
//}

