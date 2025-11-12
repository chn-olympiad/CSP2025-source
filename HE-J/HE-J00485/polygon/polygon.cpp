#include <bits/stdc++.h>
using namespace std;
const int MAXN=998244353;
vector<int> v;
int ans=0;
int n;
bool cmp(int a,int b){return a>b;}
void f(int i,int j) {
	int sum=v[j];
	for(int k=1; k<i; k++) sum+=v[j+k];
	if(sum>2*v[j]) {
		ans++;
		ans%=MAXN;
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0,t; i<n; i++) {
		cin>>t;
		v.push_back(t);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=3; i<=n; i++) {
		for(int j=0; j<v.size(); j++) {
			f(i,j);
		}
	}
	cout<<ans;
	return 0;
}
