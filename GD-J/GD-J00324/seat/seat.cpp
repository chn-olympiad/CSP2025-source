#include <bits/stdc++.h>
using namespace std;
int n,m,x,a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	a[1]=x;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			if(i%2==0){
				if(a[(i-1)*n+k]==x){
					cout<<i<<' '<<n-k+1;
					return 0;
				}
			}
			else{
				if(a[(i-1)*n+k]==x){
					cout<<i<<' '<<k;
					return 0;
				}
			}
		}
	}
	return 0;
}
