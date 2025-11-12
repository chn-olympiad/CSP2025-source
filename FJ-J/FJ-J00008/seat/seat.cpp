#include<bits/stdc++.h>
using namespace std;
int cmp(long long x,long long y){
	return x>y;
}
long long n,m,a[15][15],r,cj[105],cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	r=cj[1];
	sort(cj+1,cj+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=cj[cnt];
				cnt++;
			}
		}else{
			for(int j=n;j>=1;j--){
				a[j][i]=cj[cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==r){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
