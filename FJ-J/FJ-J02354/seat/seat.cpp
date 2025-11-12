#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000];
bool cmp(int b,int c){
	return b>c;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int p=a[1],d=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				++d;
				if(a[d]==p){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				++d;
				if(a[d]==p){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
