#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int fs=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int d=1;
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				if(a[d]==fs){
					cout<<j<<" "<<i;
					return 0;
				}
				d++;
			}
		}
		else{
			for(int i=n;i>0;i--){
				if(a[d]==fs){
					cout<<j<<" "<<i;
					return 0;
				}
				d++;
			}
		}
	}
	return 0;
}
