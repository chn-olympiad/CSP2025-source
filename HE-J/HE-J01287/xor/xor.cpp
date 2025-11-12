#include<bits/stdc++.h>
using namespace std;
int n,k,ans,t;
int a[500005];
vector<int> v;
map<pair<int,int>,int>m;
void solve(int x) {
	for(int i=x+1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			int sum=a[i];
			if(!m[ make_pair(i,j)]) {
				for(int m=i+1; m<=j; m++) {
					sum^=a[m];
				}
				m[ make_pair(i,j)]=sum;

			}
			else sum=m[ make_pair(i,j)];

			if(sum==k) v.push_back(sum);

			solve(j);
			ans=max(ans,(int)v.size());

			if(sum==k)	v.pop_back();

		}

	}
}
int main() {
//	freopen("xor.in","r",stdin);
//	freopen("xor.ans","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	solve(0);
	cout <<ans;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
