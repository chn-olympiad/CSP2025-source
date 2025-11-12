#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ps[500005];
int ans;
vector<pair<int,int> >correct_seqs;
int query(int s,int e){
	return ps[s-1] xor ps[e];
}

bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.first!=b.first) return a.first<b.first; 
	else return (a.second-a.first)<(b.second-b.first);//长度小的优先(贪心)
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ps[i] = ps[i-1] xor a[i];
	}
	for(int i=1;i<=n;i++){//保存所有的可用区间
		for(int j=i;j<=n;j++){
			if(query(i,j) == k) correct_seqs.emplace_back(make_pair(i,j));
		}
	}
	sort(correct_seqs.begin(),correct_seqs.end(),cmp);
	int now_at = 0;
	for(int i=0;i<correct_seqs.size();i++){
		if(now_at<correct_seqs[i].first){
			ans++;
			now_at=correct_seqs[i].second;
		}
	}
	cout<<ans;
	return 0;
}