#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
ll n,m,ans,sum;
int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>ans;
	for(int i=2,j;i<=n*m;++i){
		cin>>j;
		if(j>ans){
			sum++;
		}
	}
	sum++;
	cout<<(sum%n==0? sum/n : sum/n+1 )<<" "<<( (sum%n==0?sum/n:sum/n+1)%2==0 ? n-(sum%n==0?sum%n:sum%n-1):sum%n==0?n:sum%n);
	return 0;
}


