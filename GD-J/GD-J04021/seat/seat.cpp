#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,ans;
int a[N],R,I,b[N][N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[++ans]==R){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>0;j--){
				if(a[++ans]==R){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
