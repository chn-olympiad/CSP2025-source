#include<bits/stdc++.h>
using namespace std;
int a[15][15],s[225];
bool cop(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int fs;
	cin>>fs;
	for(int i=1;i<=n*m-1;i++){
		cin>>s[i];
	}
	s[m*n]=fs;
	sort(s+1,s+1+n*m,cop);
	int x,y;
	int cnt=1;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				a[i][j]=s[cnt];
				cnt++;
			}
		}
		if(j%2==0){
			for(int i=n;i>=1;i--){
				a[i][j]=s[cnt];
				cnt++;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==fs){
				x=i,y=j;
				cout<<y<<" "<<x;
				return 0;
			}
		}
	}
	return 0;
} 
