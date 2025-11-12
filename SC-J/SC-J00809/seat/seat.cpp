#include <bits/stdc++.h>
using namespace std;
int n,m,num,a[105],pos=0,ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> num;
	for(int i=0;i<n*m-1;++i){
		cin >> a[i];
	}
	sort(a,a+n*m-1,cmp);
	for(int i=0;i<n*m-1;++i){
		if(num>a[i]){
			pos=i+1;
			break;
		}
	}
	if(pos==0)pos=n*m;
	if(pos%n!=0)ans=pos/n+1;
	else ans=pos/n;
	cout << ans << ' ';
	if(ans%2==1){
		if(pos%n==0)cout << m;
		else cout << pos%n;
	}
	else{
		if(pos%n==0)cout << 0;
		else cout << m-pos%n+1;
	}
	return 0;
}