#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,a;
	cin>>n>>m>>a;
	long long cnt=1;
	for(int i=2;i<=n*m;i++){
		int b;
		cin>>b;
		if(b>a) cnt++;
	}
	int h=(cnt+n-1)/n,l=(cnt-1)%n+1;
	cout<<h<<" ";
	if(h%2==1){
		cout<<l;
	}else{
		cout<<n+1-l;
	}
	return 0;
}