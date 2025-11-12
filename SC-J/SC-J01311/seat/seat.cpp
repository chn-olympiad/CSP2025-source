#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[110];
int r;
bool cmp(int x,int y){
	return x>y;
}
void seat(int x,int y){
	if(x%2==0){
		cout<<x<<' '<<n-y+1;
		return;
	}
	cout<<x<<' '<<y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i*m-m+j]==r){
				seat(i,j);
				break;
			}
		}
	}
	return 0;
} 