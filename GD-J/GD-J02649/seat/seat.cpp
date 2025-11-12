#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,k,p,l=1,op;
int a[N],s[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			p=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				s[j][i]=a[++op];
			}
		}else{
			for(int j=n;j>=1;j--){
				s[j][i]=a[++op];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==k){
				cout<<j<<' '<<i<<'\n';
			}
		}
	}
	return 0;
}
