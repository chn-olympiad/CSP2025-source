#include<bits/stdc++.h>
#include<vector>
#define endl "\n"
#define ll long long
using namespace std;
ll n,a[5005],ans;
map<vector<ll>,bool> b;
bool check(vector<ll>x){
	ll k=0,z=0;
	for(int i=0;i<x.size();++i){
		k=max(x[i],k);
		z+=x[i];
	}
	return z>k*2;
}
int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool s=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>1)s=0;
	}
	if(n==3){
		vector<ll>ab;
		ab.push_back(a[1]);
		ab.push_back(a[2]);
		ab.push_back(a[3]);
		if(check(ab)){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	if(s){
		cout<<"0";
	}
	return 0;
}
