#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100005][5],h[100005][5],id[100005],rzd,s;
struct BM{
	int dj,id;
};
vector<BM>bm[5];
bool cmp(BM x,BM y){
	return x.dj>y.dj;
}
int RZD(){
	if(bm[1].size()>=max(bm[2].size(),bm[3].size()))return 1;
	if(bm[2].size()>=max(bm[1].size(),bm[3].size()))return 2;
	return 3;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		rzd=0,s=0;
		memset(a,0,sizeof(a));
		memset(h,0,sizeof(h));
		memset(id,0,sizeof(id));
		bm[1].clear(),bm[2].clear(),bm[3].clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>a[i][j];
			if(a[i][1]>=max(a[i][2],a[i][3])){
				id[i]=1;
				if(a[i][2]<=a[i][3])h[i][1]=3,h[i][3]=2;
				if(a[i][2]>=a[i][3])h[i][1]=2,h[i][2]=3;
			}
			else if(a[i][2]>=max(a[i][1],a[i][3])){
				id[i]=2;
				if(a[i][1]<=a[i][3])h[i][2]=3,h[i][3]=1;
				if(a[i][1]>=a[i][3])h[i][2]=1,h[i][1]=3;
			}
			else if(a[i][3]>=max(a[i][1],a[i][2])){
				id[i]=3;
				if(a[i][1]<=a[i][2])h[i][3]=2,h[i][2]=1;
				if(a[i][1]>=a[i][2])h[i][3]=1,h[i][1]=2;
			}
			
			bm[id[i]].push_back(BM{a[i][id[i]]-a[i][h[i][id[i]]],i});
			s+=a[i][id[i]];
		}
		while(max(bm[1].size(),max(bm[2].size(),bm[3].size()))>n/2){
			rzd=RZD();
			sort(bm[rzd].begin(),bm[rzd].end(),cmp);
			while(bm[rzd].size()>n/2){
				bm[h[bm[rzd][bm[rzd].size()-1].id][id[bm[rzd][bm[rzd].size()-1].id]]].push_back(BM{a[bm[rzd][bm[rzd].size()-1].id][id[bm[rzd][bm[rzd].size()-1].id]]-a[bm[rzd][bm[rzd].size()-1].id][h[bm[rzd][bm[rzd].size()-1].id][id[bm[rzd][bm[rzd].size()-1].id]]],bm[rzd][bm[rzd].size()-1].id});
				s-=bm[rzd][bm[rzd].size()-1].dj;
				bm[rzd].pop_back();
			}
		}
		cout<<s<<"\n";
	}
	return 0;
}
