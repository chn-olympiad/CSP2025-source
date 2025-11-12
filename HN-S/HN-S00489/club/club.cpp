#include<bits/stdc++.h>
using namespace std;
struct node {
    int a,b,c;
};
struct node2 {
	int ab,ac,bc;
};
bool cmp1(node x,node y) {
	return x.a>y.a;
}
void slove() {
	int n;
	cin>>n;
	node d[100005];
	node2 d2[100005];
	for(int i=1; i<=n; i++) {
		cin>>d[i].a>>d[i].b>>d[i].c;
	}
	sort(d+1,d+n+1,cmp1);
	int ans=0;
	for(int i=1; i<=n/2; i++) {
		ans+=d[i].a;
	}
	cout<<ans<<endl;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		slove();
	}
}

