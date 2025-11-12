#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	int mark=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for (int j=1;j<=m;j++){
		if (j%2==1){
			for (int i=1;i<=n;i++){
				if (a[++cnt]==mark){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else{
			for (int i=n;i>=1;i--){
				if (a[++cnt]==mark){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
