#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1]) cnt++;
	}int l=cnt/n;
	if(cnt%n>0) l++;
	if(l%2==1&&cnt%n!=0) cout<<l<<" "<<cnt%n;
	else if(l%2==1&&cnt%n==0) cout<<l<<" "<<n;
	else if(l%2==0&&cnt%n!=0) cout<<l<<" "<<n-cnt%n+1;
	else cout<<l<<" "<<1;
}

