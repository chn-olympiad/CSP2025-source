#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=104;
ll n,m,r,x,y,id,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	id=n*m;
	x=y=1;
	while(true){
		if(a[id]==r){
			cout<<x<<' '<<y;
			return 0;
		}
		id--;
		if(x&1){
			if(y==n){
				x++;
			}else{
				y++;
			}
		}else{
			if(y==1){
				x++;
			}else{
				y--;
			}
		}
	}
}
