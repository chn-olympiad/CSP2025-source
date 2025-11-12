#include<bits/stdc++.h>
using namespace std;
int n,m,a[201],t,ma[11][11];
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
	t=a[1];
	int cnt=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ma[j][i]=a[++cnt];
				if(ma[j][i]==t){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				ma[j][i]=a[++cnt];
				if(ma[j][i]==t){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
} 