#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],ans=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) ans++;
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ans--;
				if(ans==0){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				ans--;
				if(ans==0){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
