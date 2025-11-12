#include <bits/stdc++.h>
using namespace std;
long long n,m,a[110],r,b[110][110],s=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+(n*m)+1,greater<int>());
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				b[i][j]=a[s];
				s++;
			}
		}else{
			for(int j=m;j>=1;j--){
				b[i][j]=a[s];
				s++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==r){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
