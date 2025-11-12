#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int a[500005];
vector<pair<int,int> > t;
bool cmp(pair<int,int> x, pair<int,int> y){
	int p=x.second-x.first;
	int q=y.second-x.first;
	if(x.second != y.second){
		return x.second<y.second;
	}
	else return p<q;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(a,0,sizeof(a));
	cin>>n>>k;
	for(int i=1; i <= n; i++){
		cin>>a[i];
		a[i] ^= a[i-1];
		for(int j=0; j < i; j++){
			if((a[i]^a[j]) == k){
				t.push_back({j+1,i});
			}
		}
	}
	sort(t.begin(),t.end(),cmp);
	int s = t.size(),rr=0;
	for(int i=0; i < s; i++){
		if(t[i].first > rr){
			ans++;
			rr = t[i].second;
		}
	}
	cout<<ans;
	return 0;
}
