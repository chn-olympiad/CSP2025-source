#include<bits/stdc++.h>
using namespace std;
int n,m,l,a[105],s[15][15],R;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++)
		cin>>a[i];
	R=a[1];
	sort(a+1,a+l+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==0)
			for(int j=n;j>=1;j--)
				s[i][j]=a[++cnt];
		else
			for(int j=1;j<=n;j++)
				s[i][j]=a[++cnt];
	}for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(s[i][j]==R){
				cout<<i<<' '<<j;
				break;
			}
	return 0;
}