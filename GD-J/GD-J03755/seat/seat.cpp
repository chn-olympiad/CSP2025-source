#include <bits/stdc++.h>
using namespace std;
int n,m,c,s,a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			c++;
			if(a[c]==s){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
		for(int j=n;j>=1;j--){
			c++;
			if(a[c]==s){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
