#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n*m);
	for(auto &t:a)cin>>t;
	int st=a[0];
	sort(a.begin(),a.end(),greater<int>());
	int pos=0;
	for(int i=0;i<n*m;i++)
		if(a[i]==st){
			pos=i+1;
			break;
		}
	int l=(pos+n-1)/n,h=pos%n;
	if(h==0)h=n;
	if((l&1)==0)h=n-h+1;
	cout<<l<<" "<<h;
	return 0;
}
