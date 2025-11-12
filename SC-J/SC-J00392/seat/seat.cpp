#include <bits/stdc++.h>
using namespace std;
int a[110];
int s[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	int len=n*m;
	for(int i=0;i<len;i++){
		cin>>a[i];
	}
	x=a[0];
	sort(a,a+len,cmp);
	int idx=0;
	int j=1;
	while(1){
		for(int i=1;i<=n;i++){
			s[i][j]=a[idx];
			if(a[idx]==x){
				cout<<j<<" "<<i;
				return 0;
			}
			idx++;
		}
		j++;
		if(j>m)break;
		for(int i=n;i>=1;i--){
			s[i][j]=a[idx];
			if(a[idx]==x){
				cout<<j<<" "<<i;
				return 0;
			}
			idx++;
		}
		j++;
		if(j>m)break;
	}
//	cout<<'\n';
//	for(int i=1;i<=n;i++){
//		for(j=1;j<=m;j++){
//			cout<<s[i][j]<<" ";
//		}
//		cout<<'\n';
//	}
	return 0;
}
/*
1 10
5 6 2 1 4 10 45 89 78 3
*/