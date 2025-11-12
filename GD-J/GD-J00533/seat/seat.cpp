#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e2+10;
int a[N];
int cnt,n,m,pl,index;
int ans_x,ans_y;
bool cmp(int A,int B){
	return A>B;
}
int qz(int x,int y){
	int nu=x/y;
	if(nu*y!=x){
		return nu+1;
	}else{
		return nu;
	}
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	index=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[++cnt]==index){
				//	cout<<cnt<<endl; xx
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[++cnt]==index){
					//cout<<cnt<<endl; y
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
