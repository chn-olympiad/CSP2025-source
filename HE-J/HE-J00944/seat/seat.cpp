#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=105;
int a[N];
int s;
int ans=1;
int t[N];
int b[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		t[ans++]=a[i];
	}
	ans=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i][j]=t[ans++];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==s){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
