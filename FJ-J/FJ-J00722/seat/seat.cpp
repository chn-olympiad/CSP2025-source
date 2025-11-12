#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105],f;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(f==a[i]){
			f=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				f--;
				if(f==0){
					cout<<i<<" "<<j;
					return 0; 
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				f--;
				if(f==0){
					cout<<i<<" "<<j;
					return 0; 
				}
			}
		}
	}
	return 0;
}
