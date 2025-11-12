#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int MOD = 998244353;
const int MAXn = 5e3+5;
LL ans=0,n,a[MAXn];

struct Node{
	LL p,sum,count,maxx;
	bool pre;
};

Node nde(LL p,LL s,LL c,LL m){
	Node tmp;
	tmp.p = p;
	tmp.count = c;
	tmp.maxx = m;
	tmp.sum = s;
	return tmp;
}

stack<Node> stk;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
		
	
	Node tmp = nde(0,0,0,-1);
	stk.push(tmp);
	while(!stk.empty()){
		Node u = stk.top();
		LL p = u.p;
		LL sum = u.sum;
		LL maxx = u.maxx;
		LL count = u.count;
		stk.pop();
		
		
		Node v;
		if (p == n) continue;
		v = nde(p+1,sum+a[p+1],count+1,max(maxx,a[p+1]));
		if (v.count>=3 && v.sum > v.maxx*2) ans = (ans+1)%MOD;
		stk.push(v);
		v = nde(p+1,sum,count,maxx);
		stk.push(v);
	}
	
	cout<<ans;
	
	return 0;
}

/*
5
1 2 3 4 5

5
2 2 3 8 10

*/






