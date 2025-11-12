#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,wh;
struct ly{
	int num,sum;
}a[10001];
bool cmp(ly a,ly b){
	return a.sum>b.sum;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sum;
		a[i].num=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			wh=i;
			break;
		}
	}
	int k=(wh+n-1)/n;
	wh=wh%n;
	cout<<k<<" ";
	if(k%2==1){
		if(wh!=0)cout<<wh;
		else cout<<n;
	}
	else {
		if(wh!=0)cout<<n-wh+1;
		else cout<<1;
	}
	return 0;
}
