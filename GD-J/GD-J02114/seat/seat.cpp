#include <bits/stdc++.h>
using namespace std;
int n,m,d,cnt;
int a[1005],s[15][15];
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sum=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n;i++){
		if(d==0){
			for(int j=1;j<=m;j++){
				s[i][j]=a[++cnt];
			}
			d=1;
		}else{
			for(int j=m;j>=1;j--){
				s[i][j]=a[++cnt];
			}
			d=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==sum){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
