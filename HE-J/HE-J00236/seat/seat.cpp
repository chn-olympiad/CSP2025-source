#include<bits/stdc++.h>
using namespace std;
const int N=14;
int a[N][N],s[N*N],n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int xm=s[1];
	sort(s+1,s+1+n*m,cmp);
	int cnt=1;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				a[i][j]=s[cnt];
				cnt++;	
			}
		}
		else{
			for(int i=n;i>=1;i--){
				a[i][j]=s[cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==xm){
				cout<<j<<' '<<i;
			    return 0;
			} 
		}
	}
	return 0;
}
