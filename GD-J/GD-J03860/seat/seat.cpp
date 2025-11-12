#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],sc,r=1,c=1;
int v[N][N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	sc=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i]==sc){
			cout<<c<<" "<<r<<endl;
//			break;
		} 
//		cout<<r<<" "<<c<<endl;
		v[r][c]=a[i];
		if(r==n&&c&1||r==1&&!(c&1)) ++c;
		else if(c&1) ++r;
		else if(!(c&1)) --r;
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=m;++j){
//			cout<<v[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}

