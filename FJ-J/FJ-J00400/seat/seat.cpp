#include <bits/stdc++.h>
using namespace std;        
int n,m,c;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	c=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int u=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[u]==c){
					cout<<i<<' '<<j;
				}
				u++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[u]==c){
					cout<<i<<' '<<j;
				}
				u++;
			}
		}
	}
	return 0;
}
