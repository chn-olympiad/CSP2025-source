#include <bits/stdc++.h>
using namespace std;
struct node {
	int f,nt;
};
bool cmp(node x,node y) {
	return x.f>y.f;
}
int n,m,pos;
vector<node> a;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0,x;i<n*m;i++) {
		cin>>x;
		a.push_back({x,i+1});
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<n*m;i++)
		if(a[i].nt==1) {
			pos=i;
			break;
		}
	cout<<(pos/n+1)<<' ';
	if(((pos/n+1)%2)==1) {
		cout<<(pos%n+1);
	} else if(((pos/n+1)%2)==0) {
		cout<<(n-(pos%n));
	}
	return 0;
} 
