#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],s[11][11],r;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}r=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if((i/n)%2==0){
			s[i%n][i/n]=a[i];
		}else{
			s[n-i%n-1][i/n]=a[i];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]==r) cout<<j+1<<" "<<i+1;
		}
	}
	return 0;
}
