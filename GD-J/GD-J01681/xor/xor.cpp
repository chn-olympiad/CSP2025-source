#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,k;
int a[N];
int dp[N];
int cnt=0;
vector<pair<int,int> > v;
int l_r_xor(int l,int r){
	return dp[r]^dp[l-1];
}
int cmp(pair<int,int> a,pair<int,int> b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=dp[i-1]^a[i]; 
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int x=l_r_xor(l,r);
			if(x==k){
				v.push_back(make_pair(l,r));
				break;
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	int l=0,r=0;
	for(auto p:v){
		if(p.first>r){
			r=p.second;
			cnt++; 
		} 
	}
	cout<<cnt;
	
	return 0;
}
