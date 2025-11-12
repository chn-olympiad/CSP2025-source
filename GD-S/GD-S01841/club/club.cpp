#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int maxn=1e5+100;
int a[maxn][5];
priority_queue<pair<int,pair<int,pair<int,pair<int,int>>>>,vector<pair<int,pair<int,pair<int,pair<int,int>>>>>,greater<pair<int,pair<int,pair<int,pair<int,int>>>>>> q[4];
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			int ma1=-100,pos1,pos2,ma2=-100,pos3,ma3=-100;
			for(int j=1;j<=3;j++){
				if(ma1<a[i][j]){
					ma1=a[i][j];
					pos1=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(ma2<a[i][j]&&j!=pos1){
					ma2=a[i][j];
					pos2=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(ma3<a[i][j]&&j!=pos1&&j!=pos2){
					ma3=a[i][j];
					pos3=j;
				}
			}
			if(q[pos1].size()<(n/2)){
				q[pos1].push({ma1,{-ma2,{ma3,{pos2,pos3}}}});
			}
			else{
				pair<int,pair<int,pair<int,pair<int,int>>>> o=q[pos1].top();
				if(o.x<ma1){
					q[pos1].pop();
					q[pos1].push({ma1,{-ma2,{ma3,{pos2,pos3}}}});
					if(q[o.y.y.y.x].size()<(n/2)){
						q[o.y.y.y.x].push({-o.y.x,{-o.y.y.x,{-1,{o.y.y.y.y,-1}}}});
					}
				    else{
						pair<int,pair<int,pair<int,pair<int,int>>>> p=q[o.y.y.y.x].top();
						if(p.x<(-o.y.x)){
							q[o.y.y.y.x].pop();
							q[o.y.y.y.x].push({-o.y.x,{-o.y.y.x,{-1,{o.y.y.y.y,-1}}}});
							q[p.y.y.y.x].push({-p.y.x,{-p.y.y.x,{-1,{p.y.y.y.y,-1}}}});
						}
						else{
							if((-p.y.x)>(-o.y.x)){
								q[o.y.y.y.x].pop();
						    	q[o.y.y.y.x].push({-o.y.x,{-o.y.y.x,{-1,{o.y.y.y.y,-1}}}});
						    	q[p.y.y.y.x].push({-p.y.x,{-p.y.y.x,{-1,{p.y.y.y.y,-1}}}});
							}
							else{
								q[o.y.y.y.y].push({-o.y.y.x,{-1,{-1,{-1,-1}}}});
							}
						}
					}
				}
				else{
					if((-o.y.x)>ma2){
						q[pos1].pop();
					    q[pos1].push({ma1,{-ma2,{ma3,{pos2,pos3}}}});
					    if(q[o.y.y.y.x].size()<(n/2)){
							q[o.y.y.y.x].push({-o.y.x,{-o.y.y.x,{-1,{o.y.y.y.y,-1}}}});
						}
					    else{
							pair<int,pair<int,pair<int,pair<int,int>>>> p=q[o.y.y.y.x].top();
							if(p.x<(-o.y.x)){
								q[o.y.y.y.x].pop();
								q[o.y.y.y.x].push({-o.y.x,{-o.y.y.x,{-1,{o.y.y.y.y,-1}}}});
								q[p.y.y.y.x].push({-p.y.x,{-p.y.y.x,{-1,{p.y.y.y.y,-1}}}});
							}
							else{
								if((-p.y.x)>(-o.y.x)){
									q[o.y.y.y.x].pop();
							    	q[o.y.y.y.x].push({-o.y.x,{-o.y.y.x,{-1,{o.y.y.y.y,-1}}}});
							    	q[p.y.y.y.x].push({-p.y.x,{-p.y.y.x,{-1,{p.y.y.y.y,-1}}}});
								}
								else{
									q[o.y.y.y.y].push({-o.y.y.x,{-1,{-1,{-1,-1}}}});
								}
							}
						}
					}
					else{
						q[pos2].push({ma2,{-ma3,{-1,{pos3,-1}}}});
					}
				}
			}
		}
		long long ans=0;
		while(!q[1].empty()){
			ans+=q[1].top().x;
			q[1].pop();
		}
		while(!q[2].empty()){
			ans+=q[2].top().x;
			q[2].pop();
		}
		while(!q[3].empty()){
			ans+=q[3].top().x;
			q[3].pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}
