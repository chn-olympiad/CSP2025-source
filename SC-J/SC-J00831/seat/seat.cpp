#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;//n行m列 
int b[15][15];
bool cmt(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	int xh=a[1];
	sort(a+1,a+n*m+1,cmt);
	//for(int i=1;i<=n*m;++i){
	//	cout<<a[i]<<" ";
	//}
	int num=1;
	for(int i=1;i<=n;++i){
		if(i%2==1){
			for(int j=1;j<=m;++j){
				if(a[num]==xh){
					cout<<i<<' '<<j;
					return 0;
				}
				++num;
			}
		}
		if(i%2==0){
			for(int j=m;j>=1;--j){
				if(a[num]==xh){
					cout<<i<<' '<<j;
					return 0;
				}
				++num;
			}
		}
	}
	return 0;
}