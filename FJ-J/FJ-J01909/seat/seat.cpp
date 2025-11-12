#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[100000],r,t,s[20][20];
bool cmp(int a1,int a2){
	return a1>a2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++) cout<<a[i];
	//return 0;
	for(int i=1;i<=n*m;i++){
		int x=int(ceil(i*1.0/n)),y;
		if(x%2==1){
			y=i%n;
			if(y==0) y=n;
		}
		else{
			y=i%n;
			if(y==0) y=n;
			y=n-y+1;
		}
		s[y][x]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) if(s[i][j]==r){
			cout<<j<<" "<<i;
			return 0;
		}
	}
	return 0;
}


