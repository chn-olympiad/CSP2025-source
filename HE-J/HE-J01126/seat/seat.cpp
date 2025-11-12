#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],t,id,k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				if(a[++id]==k){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[++id]==k){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
 return 0;
}
