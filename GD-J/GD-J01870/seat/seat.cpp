#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
struct qwe{
	int x,id;
}a[105];
bool cmp(qwe a,qwe b){
	return a.x > b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
		cin >> a[i].x,a[i].id=i;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt ++ ;
				if(a[cnt].id==1){
					cout << i << ' ' << j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt ++ ;
				if(a[cnt].id==1){
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
