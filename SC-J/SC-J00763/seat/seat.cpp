#include<bits/stdc++.h>
using namespace std;

int n,m; 
int a[105];
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k = a[1];
	bool t = 0;
	sort(a+1,a+n*m+1,cmp);
	int cnt = 1;
	for(int i=1;i<=m;i++){
		if(t==0){
			for(int j=1;j<=n;j++){
				if(a[cnt]==k){
					cout<<i<<' '<<j;
					return 0;
				}
				cnt++;
			}
			t = 1;
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[cnt]==k){
					cout<<i<<' '<<j;
					return 0;
				}
				cnt++;
			}
			t = 0;
		}
	}
	return 0;
}