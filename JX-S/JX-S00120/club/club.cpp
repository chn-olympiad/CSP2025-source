#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>> mv;
map<int,vector<int>> mve;
map<int,vector<int>> mav;
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	int m;
	int a,b,c,maxn=0,minn=0,d=0;
	int zong=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		for(int j=1;j<=m;j++){
			cin>>a>>b>>c;
			mv[j].push_back(a);
			mv[j].push_back(b);
			mv[j].push_back(c);
			mve[j].push_back(a);
			mve[j].push_back(b);
			mve[j].push_back(c);
		}
		for(int j=1;i<=m;j++){
			maxn=0;
			minn=0;
			sort(mv[j].begin(),mv[j].end());
			for(auto o:mv[j]){
				maxn=max(o,maxn);
				minn=min(o,minn);
			}
			for(int k=1;k<=3;k++){
				for(auto o:mve[k]){
					if(o==maxn){
						d=k;
					}
				}
			}
			mav[d].push_back(maxn);
		}
		for(int k=1;k<=m;k++){
			for(auto z:mav[k]){
				zong+=z;
				cout<<k;
			}
		}
		cout<<zong<<endl;
	}
	return 0;
}
