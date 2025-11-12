#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k;
	cin>>k;
	for(int i=1;i<=n*m-1;i++){
		int t;
		cin>>t;
		cnt+=(k<t);
	}
	int x=cnt/n+(cnt%n!=0);
	cnt%=n;
	if(cnt==0) cnt=n;
	int y;
	if(x%2==1) y=cnt;
	else y=n-cnt+1;
	cout<<x<<" "<<y;
	return 0;
}