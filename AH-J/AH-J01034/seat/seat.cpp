#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	cnt=a[1];
	sort(a+1,a+1+n*m,cmp);
	int ind;
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			ind=i;
			break;
		}
	}
	cout<<(ind-1)/n+1;
	int b=(ind-1)/n+1;
	ind-=((ind-1)/n)*n;
	if(b%2==0) cout<<" "<<n-ind+1;
	else cout<<" "<<ind;
	return 0;
}
