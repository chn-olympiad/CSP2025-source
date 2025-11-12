#include<bits/stdc++.h>
using namespace std;
long long n=1,m;
struct weizhi{
	long long cj;
	long long wz;
}k[101];
bool px(weizhi a,weizhi b){
	return a.cj>b.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>k[n*(i-1)+j].cj ;
			k[n*(i-1)+j].wz=n*(i-1)+j;
		}
	}
	sort(k+1,k+n*m+1,px);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(k[n*(i-1)+j].wz==1){
				cout<<i<<' ';
				if(i%2==0)
				cout<<m-j+1;
				else
				cout<<j;
			}
		}
	}
	return 0;
}
/*3 3
  94 95 96 97 98 99 100 93 92
*/
