#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{
	int val,id;
}a[105],seat[15][15];
bool cmp(stu a,stu b){
	return a.val>b.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				seat[i][j]=a[(i-1)*n+j];
			}
		}else{
			for(int j=n;j>=1;j--){
				seat[i][j]=a[i*n-j+1];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(seat[i][j].id==1){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
