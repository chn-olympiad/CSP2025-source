#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[105];
int x,cnt=0;
int s[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=m;j++){
				s[j][i]=a[++cnt];
			}
		}
		else{
			for(int j=m;j>=1;j--){
				s[j][i]=a[++cnt];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
//			cout<<s[i][j]<<' ';
			if(s[i][j]==x){
				cout<<j<<' '<<i;
				return 0;
			}
		}
//		cout<<endl;
	}
	return 0;
}