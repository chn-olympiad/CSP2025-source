#include<bits/stdc++.h>
using namespace std;
#define fo(i,begin,end) for(int i=begin;i<=end;i++)
int n,m,a[105],x;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	fo(i,1,n*m) cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	fo(i,1,n*m) if(a[i]==x){
		int ans;
		if(i%n==0) ans=i/n;
		else ans=i/n+1;
		cout<<ans<<" ";
		if(ans%2==1) cout<<i-n*(ans-1);
		else cout<<n-(i-n*(ans-1))+1;
		return 0;
	}
	return 0;
}