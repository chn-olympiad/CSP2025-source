#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n,m;
int r;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++cnt];
		}
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(a[++cnt]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				if(a[++cnt]==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
//written by smartjohn