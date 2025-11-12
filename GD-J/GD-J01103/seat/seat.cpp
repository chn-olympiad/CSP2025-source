#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],s[105][105];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int men=n*m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+men+1,cmp);
	int j=1;
	for(int i=1;i<=men;i++){
		if(j%2==1){
			s[j][(i-1)%m+1]=a[i];
			if(a[i]==r) {
				cout<<j<<" "<<(i-1)%m+1;
				return 0;
			}
		}else{
			s[j][m-(i-1)%m]=a[i];
			if(a[i]==r){
				cout<<j<<" "<<m-(i-1)%m;
				return 0;
			}
		}
		if(i%m==0) j++;
	}
}
