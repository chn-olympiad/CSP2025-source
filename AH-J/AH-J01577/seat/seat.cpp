//数据这么小，还是第2题，感觉有古怪
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ll sum=a[1],x=1,y=1,tot=n*m+1;
	sort(a+1,a+n*m+1);
	//for(ll i=1;i<=n*m;i++){
	//	cout<<a[i];
	//}
	while(1){
		//cout<<x<<' '<<y<<'\n';
		tot--;
		if(a[tot]==sum){
			cout<<x<<' '<<y<<'\n';
			return 0;
		}
		if(x%2==0){
			if(y==1){
				x++;
			}else{
				y--;
			}
		}else{
			if(y==n){
				x++;
			}else{
				y++;
			}
		}
	}
	return 0;
}
