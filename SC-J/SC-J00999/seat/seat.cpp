#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
string s;
int n,m,a[N],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) cnt++;
	}
	cnt++;
	int l=cnt/n,r;
	if(cnt%n!=0) cnt-=l*n,l++;
	if(l%2==1) r=cnt;
	else r=n-cnt+1;
	cout<<l<<" "<<r;
	return 0;
}