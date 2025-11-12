#include<bits/stdc++.h>
using namespace std;

int a[105];
int s[15][15];

bool cmp(int x,int y){
	return x>y;
}

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];	
	}
	int sum=a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<' ';
//	}
	int tail=1; 
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				s[j][i]=a[tail++];
			}
		}else{
			for(int j=n;j>=1;j--){
				s[j][i]=a[tail++];
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++){
//				cout<<s[i][j]<<' ';
//		}
//		cout<<"\n";
//	}
//	cout<<"\n";
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]==sum){
				cout<<j<<' '<<i;
				break;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	return 0;
}//awa

