#include<bits/stdc++.h>
using namespace std;
int a[2000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int zz=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[zz++];
		}
	}
	int rs=a[1],pl=0;
	sort(a+1,a+zz,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==rs){
			pl=i;
			break;
		}
	}
	for(int j=1;j<=m;j++){
		if(j%2){
			for(int i=1;i<=n;i++){
				pl--;
				if(pl==0){
					cout<<j<<' '<<i<<'\n';
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				pl--;
				if(pl==0){
					cout<<j<<' '<<i<<'\n';
					return 0;
				}
			}
		}
	}
}