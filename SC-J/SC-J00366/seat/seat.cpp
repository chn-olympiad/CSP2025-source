#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int m,n;cin>>n>>m;
	vector<int>B(n*m);
	for(int &i:B)cin>>i;
	int self=B[0];
	sort(B.begin(),B.end(),greater<int>());
	int t=find(B.begin(),B.end(),self)-B.begin()+1;
	if(t%(2*n)<=n){
		if(t%(2*n)!=0){
			if(t%n==0)cout<<t/n<<' '<<n;
			else cout<<t/n+1<<' '<<t%n;
		}
		else cout<<t/n<<' '<<n;
	}
	else{
		cout<<t/n+1<<' '<<n-t%n+1;
	}
	return 0;
}