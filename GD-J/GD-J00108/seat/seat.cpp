#include<bits/stdc++.h>
using namespace std;
int n,m,r;
vector<pair<int,int>> a(105);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		int x;
		cin>>x;
		a[i].first=-x;
	}
	a[1].second=1;
	sort(a.begin()+1,a.begin()+1+n*m);
	for(int i=1;i<=n*m;i++) {
		if(a[i].second==1) {
			r=i;
			break;
		}
	}
	int t1=r/n,t2=r%n;
	if(t2==0) 
		t2=n;
	else t1++;
	cout<<t1<<" ";
	if(t1&1) 
		cout<<t2;
	else 
		cout<<n-t2+1;
	
	return 0;
}
