#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,sum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) sum=a[i];
	}
	sort(a+1,a+1+t,cmp);
	int bi=0;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				bi++;
				if(a[bi]==sum){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				bi++;
				if(a[bi]==sum){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
