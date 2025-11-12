#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
int a[200];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+n*m,cmp);
	int xh;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			xh=i;
			break;
		}
	}
	int l=xh/n;
	if(xh%n) l++;
	int cha=xh-(l-1)*n;
	int h;
	if(l%2){
		h=cha;
	}
	else{
		h=n+1-cha;
	}
	cout<<l<<" "<<h;
	return 0;
}
