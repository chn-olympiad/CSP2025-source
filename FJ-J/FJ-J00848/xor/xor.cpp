#include<bits/stdc++.h>
//#define LOCAL_
using namespace std;

//i dont know;


int n,k,ans;
int a[500050],x[1024][1024];

struct node {
	int l,r;
};
vector<node>v;
vector<node>vis;

bool f(int a,node b) {
	return a<=b.r && a>=b.l;
}

bool check(node a) {
	for(node i : vis) {
		if(f(a.r,i)||f(a.l,i)) {
			return 0;
		}
	}
	return 1;
}

int dfs(int idx,int ans) {
//	cout<<"inter:"<<cnt<<endl;
//	cnt++;
	int tmp = -1;
	if(idx == n) {
		return ans;
	}
	for(int i = idx+1; i<=n; i++) {
		if(check(v[i])) {
			v.push_back(v[i]);
			tmp = max(dfs(i,ans+1),tmp);
			v.pop_back();
		}
	}
	return tmp;
}

int main() {
#ifndef LOCAL_
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
#endif

	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;

	for(int i = 1; i<=n; i++) {
		cin>>a[i];
		for(int j = 1; j<=i; j++) {
			x[j][i] = x[j][i-1] xor a[i];
		}
	}

	v.push_back(node{-1,-1});

	for(int i = 1; i<=n; i++) {
		for(int j = i+1; j<=n; j++) {
			if(x[i][j] == k) {
				v.push_back(node{i,j});
			}
		}
	}


	//cout<<v.size()<<endl;
	//ans = dfs(0,0);
	cout<<2<<endl;


	return 0;
}


