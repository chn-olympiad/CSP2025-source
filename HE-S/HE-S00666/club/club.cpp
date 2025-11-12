#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdio.h>
using namespace std;
const int maxn=100010;

bool comp(const pair<int,int> &a,const pair<int,int> &b){
	return (a.first>b.first);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while (T--){
		int n;
		cin>>n;
		int lim=n/2;
		vector<vector<pair<int,int> > > v(maxn); // v:{  {  {dat,i(max)},{dat,i(mid)}  },...} ,i belong_to 0,1,2
		int cnt[3]={0,0,0};
		int cnti[3][maxn]; // store i 
		for (int i=1;i<=n;i++){
			int d[3];
			scanf("%d%d%d",d,d+1,d+2);
			for (int j=0;j<=2;j++){
				v[i].push_back(pair<int,int>(d[j],j));
			}
			sort(v[i].begin(),v[i].end(),comp);
			cnti[v[i][0].second][cnt[v[i][0].second]]=i;
			cnt[v[i][0].second]++;
		}
		int c=-1;
		for (int cq=0;cq<3;cq++){
			if (cnt[cq]>lim) c=cq;
		}
		int res=0;
		for (int i=1;i<=n;i++){
			res+=v[i][0].first;
		}
		if (c!=-1) {
			int de[maxn];
			for (int i=0;i<cnt[c];i++){
				int j=cnti[c][i];
				de[i]=v[j][0].first-v[j][1].first;
			}
			sort(de,de+cnt[c]);
			for (int i=0;i<cnt[c]-lim;i++){
				res-=de[i];
			}
		}
		cout<<res<<endl;
	}
	return 0;
}

