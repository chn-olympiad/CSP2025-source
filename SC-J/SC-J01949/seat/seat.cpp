#include<bits/stdc++.h>
#define int long long
const int N=2000+5;
using namespace std;
int n,m;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a[0] = a[1];
	int l=1,h=1;
	sort(a+1,a+1+n*m,cmp);
	int posl,posh; 
	for(int i=1;i<=n*m;i++){
		if(a[i] == a[0]){
			posl = l,posh = h;
			break;
		}
		l++;
		if(l == 0) l++,h++;
		if(l == n+1) l = -n,h++;
	}
	cout<<abs(posh)<<" "<<abs(posl);
	return 0;
}
// If most of the poeple are sleeping in night

