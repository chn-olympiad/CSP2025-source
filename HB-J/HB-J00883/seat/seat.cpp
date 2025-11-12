#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int t=a[0];
	sort(a,a+n*m,cmp);
	int k=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[k++]==t)cout<<i<<" "<<j;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[k++]==t)cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
