#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r,cnt=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				if(a[cnt]==r){
					cout<<j<<" "<<i;
					return 0;
				}
				cnt++;
			}
		}else{
			for(int i=n;i>=1;i--){
				if(a[cnt]==r){
					cout<<j<<" "<<i;
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}
