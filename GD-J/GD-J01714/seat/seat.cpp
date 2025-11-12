#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],l,r,x,cnt1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=m;i++){
		if (i%2==1){
			for (int j=1;j<=n;j++){
				cnt1++;
				if (a[cnt1]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for (int j=n;j>=1;j--){
				cnt1++;
				if (a[cnt1]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
