#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int r,ans;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	int f=0;
	for (int i=1;i<=m;i++){
		if (i%2==0&&i!=1){
			for (int j=n;j>=1;j--){
				ans++;
				if (a[ans]==r){
					f=1;
					cout<<i<<" "<<j;
					break;
				}	
			}
		}else if (i%2!=0){
			for (int j=1;j<=n;j++){
				ans++;
				if (a[ans]==r){
					f=1;
					cout<<i<<" "<<j;
					break;
				}
			} 
		}
		if (f){
			break;
		}
	}
	return 0;
}
