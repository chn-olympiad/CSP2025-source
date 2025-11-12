#include<bits/stdc++.h>
using namespace std;
int a[1010];
int w[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	int f=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[j+(i-1)*n]==k){
					cout<<i<<" "<<j;
					f=1;
					break;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				int l=(m-j)+1;
				if(a[l+(i-1)*n]==k){
					cout<<i<<" "<<j;
					f=1;
					break;
				}
			}
		}
		if(f){
			break;
		}
	}
	return 0;
}
