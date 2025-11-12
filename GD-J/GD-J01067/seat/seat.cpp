#include<bits/stdc++.h>
#define ll long long
#define N 10005
using namespace std;
ll n,m,a[N],q,x,y;
bool f=true;
bool cmp(ll a,ll b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	q=a[1];
	sort(a+1,a+n*m+1,cmp);x=1;
	for(int i=1;i<=n*m;i++){
		if(f){
			if(y==n) x++,f=false;
			else y++;
		}
		else{
			if(y==1) x++,f=true;
			else y--;
		}
		if(q==a[i]){cout<<x<<" "<<y;return 0;}
	}
	return 0;
}
