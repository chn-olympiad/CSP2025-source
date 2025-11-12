#include<bits/stdc++.h>
using namespace std;
const int MAXN=2*1e5+10;
int T,q;
int ans;
int m[4][MAXN]; 
int k=3;
//priority_queue<pair<int,int > > que[4];//first 满意度，second 对应people 
//priority_queue<pair<int,int > > qu[MAXN];// first 满意度，second 对应club 
//int zuida;
//bool z[4];
//void dfs(int x){
//	for(int c=1;c<=3;c++){
//		if(z[c]==true)continue;
//		pair<int,int > yu=qu[x].top() ;
//		que[yu.second ].push( {yu.first,x} );
//		if(que[yu.second ] .size() >q/2){
//			pair<int,int > yi=que[yu.second ].top() ;
//			qu[yi.second ] .pop() ;
//			que[yu.second ].pop() ;
//			z[c]=true;
//			dfs(yi.second );
//			z[c]=false;
//		}else{
//			return ;
//		}
//	}
//}
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>q;
		for(int c=1;c<=q;c++){
			for(int i=1;i<=3;i++){
				cin>>m[i][c];
				if(i==3&&m[i][c]==0&&(k==3||k==2)){
					if(m[i-1][c]!=0||k==2){
						k=2;
					}
				}
				if(i==3&&m[i][c]!=0){
					return 0;
				}
//				if(m[c][i]>zuida)zuida=m[c][i];
			}
		}
		if(k==3){
			sort(m[1]+1,m[1]+1+q);
			reverse(m[1]+1,m[1]+1+q);
			int ans=0;
			for(int c=1;c<=q/2;c++){
				ans+=m[1][c];
			}
			cout<<ans<<endl;
		}
//		for(int c=1;c<=q;c++){
//			for(int i=1;i<=3;i++){
//				m[c][i]=zuida-m[c][i];
//				qu[c].push( {m[c][i],i} );
//			}
//		}
//		for(int c=1;c<=q;c++){
//			dfs(c);
//		}
//		for(int c=1;c<=q;c++){
//			pair<int,int > cu=qu[c].top() ;
//			qu[c].pop() ;
//			ans+=(zuida-cu.first );
//		}
//		cout<<ans<<endl;
//		ans=0;
//		q=0;
//		memset(m,0,sizeof(m));
//		zuida=0;
//		memset(z,false,sizeof(z));
//		for(int c=1;c<=3;c++){
//			while(!que[c].empty() )que[c].pop() ;
//		}
//		for(int c=1;c<=q;c++){
//			while(!qu[c].empty() )qu[c].pop() ;
//		}
	}
	return 0;
}
