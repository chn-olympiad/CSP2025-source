#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[15][15];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k;
	int cnt=0;
	cin>>k;
	for(int i=2;i<=n*m;i++){
		int t;
		cin>>t;
		if(t>k)cnt++;
	}
	int xx=cnt/n+1,yy=cnt%n;
	if(xx%2==1){
		cout<<xx<<" "<<yy+1;
	}
	else{
		cout<<xx<<" "<<n-yy;
	}
	return 0;
}	
