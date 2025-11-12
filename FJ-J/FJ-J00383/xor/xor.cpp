#include<bits/stdc++.h>

using namespace std;
using ll=long long;

vector<pair<int, int>> qj; // l, r


int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n,k, t;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0;i<n;i++)	{
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		t=a[i];
		if(t==k)qj.push_back({i,i});
		for(int j=i+1; j<n; j++){
			t = t xor a[j];
			if(t==k){qj.push_back({i,j});
			}	
		}
	}
	cout<<qj.size();
	
}

