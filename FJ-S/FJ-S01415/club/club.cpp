#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN = 1e5+5;
long long ans;
int n,t,byi = -1,i1,i2;
int a[MAXN][3];
vector<int> cl[3];
inline int GetMinDelta(int i){
	return min(abs(a[i][byi]-a[i][i1]),abs(a[i][byi]-a[i][i2]));
}
inline int GetNextCl(int i){
	if(abs(a[i][byi]-a[i][i1])<abs(a[i][byi]-a[i][i2]))return i1;
	else return i2;
}
bool cmp(int x,int y){
	return GetMinDelta(x)>GetMinDelta(y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])cl[0].push_back(i);
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])cl[1].push_back(i);
			else cl[2].push_back(i);
		}
		if(cl[0].size()>n/2)byi = 0,i1 = 1,i2 = 2;
		else if(cl[1].size()>n/2)byi = 1,i1 = 0,i2 = 2;
		else if(cl[2].size()>n/2)byi = 2,i1 = 0,i2 = 1;
		if(byi!=-1){
			sort(cl[byi].begin(),cl[byi].end(),cmp);
			while(cl[byi].size()>n/2){
				int top_ = cl[byi][cl[byi].size()-1];
				cl[byi].pop_back();
				cl[GetNextCl(top_)].push_back(top_);
			}
		}
		for(int i = 0;i<cl[0].size();i++)ans+=a[cl[0][i]][0];
		for(int i = 0;i<cl[1].size();i++)ans+=a[cl[1][i]][1];
		for(int i = 0;i<cl[2].size();i++)ans+=a[cl[2][i]][2];
		cout<<ans<<endl;
		cl[0].clear(),cl[1].clear(),cl[2].clear(),ans = 0;
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
