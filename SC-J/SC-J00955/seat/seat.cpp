#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1; cin>>n>>m;
	vector<int> a(n*m);
	cin>>a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]) cnt++;
	}
	int ln=cnt%(n*2),c=cnt/n,r; //cnt:第几名，c:列，r:行 
	if(!ln) r=1;
	else{
		if(ln==n) r=n;
		else{
			c++;
			if(ln<=n) r=ln;
			else r=n*2-ln+1;
		}
	}
	cout<<c<<" "<<r<<"\n";
	return 0;
}