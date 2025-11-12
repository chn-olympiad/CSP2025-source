#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	int c=a.second-a.first,d=b.second-b.first;
	return c<=d;
}
int n,k,cnt,s;
vector<int> v;
bool f(int l, int r){
	if(l==r)
		return (v[l-1]==k);
	
	int t=v[l-1];
	for(int i=l+1; i<=r; i++){
		t=t ^ v[i-1];
	}
	return t==k;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	v.resize(n);
	bool t;
	for(int& x:v) cin >> x;
	vector<pair<int,int>> a;
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			t=f(i,j);
			cnt+=t;
			if(t){
				s++;
				a.push_back(pair<int,int>(i,j));
			}
		}
	}
	sort(a.begin(),a.end(),cmp);
	pair<int,int> d=a[0];
	for(int i=1; i<s; i++){
		if(a[i].first==d.first || a[i].second==d.second || (a[i].second>d.second && a[i].first<d.first))
			cnt--;
		else d=a[i];
	}
	cout << cnt << endl;
	return 0;
}
