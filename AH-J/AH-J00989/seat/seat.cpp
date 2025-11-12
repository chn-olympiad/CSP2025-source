#include<bits/stdc++.h>
using namespace std;
int n,m,a[225],mp[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int ans=0,k=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int j=1;j<=m;j++){
		if(j%2)
			for(int i=1;i<=n;i++)
				mp[i][j]=a[++ans];
		else
			for(int i=n;i>=1;i--)
				mp[i][j]=a[++ans];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==k){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
//#Shang4Shan3Ruo6Shui4
}
