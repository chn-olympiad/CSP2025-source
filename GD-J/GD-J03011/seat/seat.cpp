#include<bits/stdc++.h>
using namespace std;
long long n,m,a[15][15],b[1005],s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>b[i];
	s=b[1];
	sort(b+1,b+n*m+1,cmp);
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(b[cnt]==s){
					cout<<i<<" "<<j<<'\n';
				}
				a[i][j]=b[cnt];
				cnt++;
			}
		}else{
			for(int j=m;j>=1;j--){
				if(b[cnt]==s){
					cout<<i<<" "<<j<<'\n';
				}
				a[i][j]=b[cnt];
				cnt++;
			}
		}
	}
	return 0;
}
