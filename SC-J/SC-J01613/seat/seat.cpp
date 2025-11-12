#include<bits/stdc++.h>
using namespace std;
int a[101],s[11][11];
bool chan(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)r=a[i];
	}
	sort(a+1,a+1+n*m,chan);
	int cnt=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				s[j][i]=a[cnt];
				cnt++;
			}
		}else{
			for(int j=n;j>=1;j--){
				s[j][i]=a[cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==r){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
