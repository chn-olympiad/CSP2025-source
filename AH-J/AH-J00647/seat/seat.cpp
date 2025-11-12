#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define F std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	F;
	int n,m,d,i,j;
	vector<int> v;
	cin>>n>>m;
	for(i=0;i<n*m;++i)cin>>d,v.push_back(d);
	d=v[0],sort(v.begin(),v.end(),greater<int>());
	auto t=lower_bound(v.begin(),v.end(),d,greater<int>())-v.begin()+1;
	i=t/n,j=t%n;
	if(i&1)cout<<i+(j!=0)<<" "<<(j>0?n-j+1:n)<<"\n";
	else cout<<i+(j!=0)<<" "<<(j>0?j:1)<<"\n";
	return 0;
}
