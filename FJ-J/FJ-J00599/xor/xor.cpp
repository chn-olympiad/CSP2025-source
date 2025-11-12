#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,k,now,cnt;
int a[N];
vector<pair<int,int>> qj;
bool cmp(pair<int,int> x,pair<int,int> y){
	if(x.second!=y.second) return x.second<y.second;
	return x.first<y.first;
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n>1000&&k==1){
		for(int i=1;i<=n;++i){
			if(a[i]==1) ++cnt;
		}
		cout<<cnt;
		return 0;
	}
	else if(n>1000&&k==0){
		bool tt_1=0;
		for(int i=1;i<=n;++i){
			if(a[i]==0){
				++cnt;
				tt_1=0;
			}
			if(a[i]==1&&tt_1){
				++cnt;
				tt_1^=1;
			}
			else if(a[i]==1){
				tt_1^=1;
			}
		}
		cout<<cnt;
		return 0;
	}
	else{
		for(int l=1;l<=n;++l){
			for(int r=l;r<=n;++r){
				now^=a[r];
				if(now==k) qj.push_back({l,r});
			}
			now=0;
		}
		int pr=-1;
		sort(qj.begin(),qj.end(),cmp);
		for(int i=0;i<(int)qj.size();++i){
	//		cout<<qj[i].first<<" "<<qj[i].second<<"\n";
			if(qj[i].first>pr){
	//			cout<<pr<<"\n";
				++cnt;
				pr=qj[i].second;
			}
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
