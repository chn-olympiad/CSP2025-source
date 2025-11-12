#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,g,s,x=1,y=1;
ll a[105];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) g=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==g) s=i;
	}
	s-=1;
	while(s--){
		if(x%2==1){
			if(y+1>n) x++;
			else y++;
		}else{
			if(y-1<1) x++;
			else y--;
		}
	}
	cout<<x<<" "<<y<<endl;
	
	return 0;
} 
