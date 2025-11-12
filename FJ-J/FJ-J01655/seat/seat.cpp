#include<bits/stdc++.h>
using namespace std;
const int N=20,M=20;
int n,m,nx,ny,cnt,T;
bool d;
int a[N*M],s[N][M];
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
	T=a[1];
	sort(a+1,a+n*m+1,cmp); 
	nx=1,ny=1,d=1,cnt=1;
	s[nx][ny]=a[cnt];
	while(cnt<n*m){
		if(d==1){
			ny++;
			if(ny>n){
				ny=n,nx++;
				d=0;
			}
			cnt++;
			s[nx][ny]=a[cnt];
		}
		else{
			ny--;
			if(ny<1){
				ny=1,nx++;
				d=1;
			}
			cnt++;
			s[nx][ny]=a[cnt];
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==T){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
