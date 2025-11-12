#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,tj,cj;
bool cmp(int a,int b){
	return  a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cj=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				tj++;
				if(a[tj]==cj){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=1;j<=m;j++){
				tj++;
				if(a[tj]==cj){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
