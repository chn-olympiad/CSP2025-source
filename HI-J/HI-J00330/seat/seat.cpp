#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	vector<long long>zy(100+10);
	for(int i=1;i<=n*m;i++)
	cin>>zy[i];
	sort(zy.begin(),zy.end());
	for(int i=1;i<=n*m;i++){
		maxn=max(maxn,zy[i]);
	}
	cout<<maxn;	
	return 0;
}
