#include<bits/stdc++.h>
using namespace std;
unsigned long long k,ans=1;
int n;
vector<unsigned long long> x;
vector<pair<int,int>> coord;
unsigned long long GetXor(int s,int e){
	unsigned long long n=0;
	for(int i=s;i<=e;i++){
		n=x[i]^n;
	}
	return n;
}
bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.second!=b.second) return a.second<b.second;
	return a.first<b.first;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	x.resize(n);
	for(int i=0;i<n;i++) cin>>x[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(GetXor(i,j)==k) coord.push_back({i,j});
		}
	}
	sort(coord.begin(),coord.end(),cmp);
	int Current=coord[0].second;
	for(pair<int,int> i:coord){
		if(i.first>Current){
			ans++;
			Current=i.second;
		}
	}
	cout<<ans;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
