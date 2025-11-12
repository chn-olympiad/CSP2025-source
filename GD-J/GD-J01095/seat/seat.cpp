#include<bits/stdc++.h>
using namespace std;
int n,m,x;
struct f{
	int s;
	int xb;
}a[1005];
bool cmp(f x,f y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].xb=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].xb==1){
			x=i;
			break;
		}
	}
	if((x%n)&&(x/n+1)%2||(x%n==0)&&(x/n)%2){
		if(x%n==0)cout<<x/n<<' '<<n;
		else cout<<x/n+1<<' '<<x%n;
	}
	else if((x%n)&&(x/n+1)%2==0||(x%n==0)&&(x/n)%2==0){
		if(x%n==0)cout<<x/n<<' '<<1;
		else cout<<x/n+1<<' '<<n-(x%n)+1;
	}
	return 0;
}
