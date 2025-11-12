#include<bits/stdc++.h>
using namespace std;
int a[15][15]={},b[110]={};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,p=0,q=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
		if(i==0){
			q=b[i];
		}
	}
	sort(b,b+n*m,cmp);
	int l=1,r=1;
	for(int i=0;i<n*m;i++){
		a[l][r]=b[i];
		if(p%2==0){
			l++;
		}
		else if(p%2!=0){
			l--;
		}
		if(l>n&&p%2==0){
			l--;
			r++;
			p++;
		}
		if(l<1&&p%2!=0){
			l++;
			r++;
			p++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==q){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
