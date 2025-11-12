#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct p{
	int xx,yy;
}a[1000001];
int cmp(p a,p b){
	return a.xx>b.xx;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i].xx;
	}
	a[1].yy++;
	sort(a+1,a+n*m+1,cmp);
//	for(int i = 1;i<=n*m;i++){
//		cout<<a[i].xx<<' '<<a[i].yy<<endl;
//	}
	int cnt=1,cnt1=0;
	for(int j = 1;j<=m;j++){
		if(cnt%2!=0){
			for(int i = 1;i<=n;i++){
				cnt1++;
//				cout<<b[i][j]<<endl;
				if(a[cnt1].yy>0){
					cout<<j<<' '<<i;
					return 0;
				}
			} 
//			cout<<' ';
			cnt++;
		}
		else{
			for(int i = n;i>=1;i--){
				cnt1++;
//				cout<<b[i][j]<<endl; 
				if(a[cnt1].yy>0){
					cout<<j<<' '<<i;
					return 0;
				}
			}
			cnt++;
//			cout<<' ';
		}
	}
	return 0;
}
