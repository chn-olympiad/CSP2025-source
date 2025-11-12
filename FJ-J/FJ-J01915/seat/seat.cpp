#include<bits/stdc++.h>
using namespace std;
long long n,m,x,a[101],sum;
bool mysort(int x,int y){
	if(x>y)	return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	a[1]=x;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,mysort);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				if(a[++sum]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[++sum]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
