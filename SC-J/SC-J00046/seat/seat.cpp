#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[15][15];
ll b[105];
ll t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>b[i];
	}
	t=b[1];
	sort(b+1,b+1+n*m,cmp);
	ll x=1,y=1;
	ll i=1;
	ll f=1;
	if(m%2==0){
		while(i<=n*m+1){
			if(b[i]==t){
				cout<<y<<' '<<x;
				return 0;
			}
			if(x==n&&y!=m){
				y++;
				i++;
				f=-f;
				if(b[i]==t){
					cout<<y<<' '<<x;
					return 0;
				}
			}
			if(x==1&&y!=1&&y!=m){
				y++;
				i++;
				f=-f;
				if(b[i]==t){
					cout<<y<<' '<<x;
					return 0;
				}
			}
			x+=f;
			i++;
		}
	}else{
		while(i<=n*m+1){
			if(b[i]==t){
				cout<<y<<' '<<x;
				return 0;
			}
			if(x==n&&y!=m){
				y++;
				i++;
				f=-f;
				if(b[i]==t){
					cout<<y<<' '<<x;
					return 0;
				}
			}
			if(x==1&&y!=1){
				y++;
				i++;
				f=-f;
				if(b[i]==t){
					cout<<y<<' '<<x;
					return 0;
				}
			}
			x+=f;
			i++;
		}
	}
	return 0;
}