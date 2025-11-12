#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],b[200005],c[200005];
ll n;	
ll num=0;
void gh(ll i,ll j,ll k,ll l,ll u){
	if(j>n/2||k>n/2||l>n/2) return;
	if(u==n) num=max(i,num);
	gh(i+a[u+1],j+1,k,l,u+1);
	gh(i+b[u+1],j,k+1,l,u+1);
	gh(i+c[u+1],j,k,l+1,u+1);
}
void ac(){
	num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	gh(a[1],1,0,0,1);
	gh(b[1],0,1,0,1);
	gh(c[1],0,0,1,1);
	cout<<num<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) ac();
	return 0;
}
