#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][3],cnt[3],type[100010];
priority_queue<pair<int,int> > q[3][3];
void solve(){
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
		int bst=-1e9,bstid=-1,bto=-1;
		for(int j=0;j<3;j++){
			int eval=-1e9,to=0;
			if(cnt[j]<n/2){
				eval=a[i][j];
				to=-1;
			}
			else{
				for(int k=0;k<3;k++)if(j!=k){
					while(1){
						if(q[j][k].size()){
							if(type[q[j][k].top().second]!=j)q[j][k].pop();
							else break;
						}
						else break;
					}
					if(!q[j][k].size())continue;
					auto _=q[j][k].top();
					if(_.first+a[i][j]>eval){
						eval=_.first+a[i][j];
						to=k;
					}
				}
			}
			if(eval>bst){
				bst=eval;
				bstid=j;
				bto=to;
			}
		}
		ans+=bst;
		if(bto!=-1){
			while(1){
				if(q[bstid][bto].size()){
					if(type[q[bstid][bto].top().second]!=bstid)q[bstid][bto].pop();
					else break;
				}
				else break;
			}
			
			auto _=q[bstid][bto].top();
			q[bstid][bto].pop();
			
			cnt[bstid]--;
			type[_.second]=bto;
			cnt[bto]++;
			
			for(int j=0;j<3;j++)if(j!=bto){
				q[bto][j].push({a[_.second][bto]-a[_.second][j],_.second});
			}
		}
		
		cnt[bstid]++;
		type[i]=bstid;
		for(int j=0;j<3;j++)if(j!=bstid){
			q[bstid][j].push({-a[i][bstid]+a[i][j],i});
		}
	}
	
	cout<<ans<<'\n';
	
	for(int i=1;i<=n;i++)type[i]=0;
	for(int i=0;i<3;i++){
		cnt[i]=0;
		for(int j=0;j<3;j++){
			while(q[i][j].size())q[i][j].pop();
		}
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
//	cout<<18961+15344+16178+19722+10557+17976+13424+8769+9953+16441; 









	return 0;
}
/*
返回弹性？怎么多测？ 

显然有 n^2 DP 做法

反悔贪心，考虑变化

每个都先选择最大值，如果填不进去了，考虑把之前的某个换下来？

需要对拍，并且显然好对拍

考虑所有可能的决策 



10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

3233232131

18961+15344+16178+19722+10557+17976+13424+8769+9953+16441






*/


