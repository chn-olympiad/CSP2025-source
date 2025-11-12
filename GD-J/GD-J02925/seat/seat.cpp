#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],k,t=1,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1],sort(a+1,a+1+n*m,greater<int>());
	for(int j=1;j<=m;j++){
		if(j%2){
			for(int i=1;i<=n;i++){
				if(a[t]==k)return cout<<j<<" "<<i,0;
				t++;
			}
		}else{
			for(int i=n;i>=1;i--){
				if(a[t]==k)return cout<<j<<" "<<i,0;
				t++;
			}
		}
	}
	return 0;
}

