#include<bits/stdc++.h>
using namespace std;

int n,m,a[110],mp[13][13];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();  cout.tie(0);
    cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int t=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				mp[i][j]=a[t];
				t++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				mp[i][j]=a[t];
				t++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(mp[j][i]==r){
				cout<<j<<' '<<i;
			}
		}
	}
	return 0;
}
