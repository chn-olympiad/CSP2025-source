#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[1005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("saat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ll temp=a[1],loca=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) if(a[i]==temp) loca=i;
	ll x=0,y=0,cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(cnt==loca) y=i,x=j;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(cnt==loca) y=i,x=j;
			}
		}
	}
	cout<<y<<" "<<x;
	return 0;
}

