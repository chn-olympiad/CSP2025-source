#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
int a[1000];
int aa[100][100];
int r;
bool cmp(int x,int y){
	return x>y;
}
int h,l;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	int no=1;
	for(int now=1;now<=m;now++)
	for(int i=1;i<=n;i++){
		if(now%2==1){
			aa[i][now]=a[no];
			no++;
		}else{
			aa[n-i+1][now]=a[no];
			no++;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<aa[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(aa[i][j]==r){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}

