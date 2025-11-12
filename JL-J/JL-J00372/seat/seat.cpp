#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+2,a+n*m+1,cmp);
	int tot=0;
	if(a[1]<a[n*m]){
		cout<<n<<" "<<m;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[++tot+1]<a[1]){
					cout<<i<<" "<<j;
					return  0;
				}
			}
		}
		if(i%2==0){
			for(int j=m;j>=1;j--){
				if(a[++tot+1]<a[1]){
					cout<<i<<" "<<j;
					return  0;
				}
			}
		}
	}
	return 0;
}