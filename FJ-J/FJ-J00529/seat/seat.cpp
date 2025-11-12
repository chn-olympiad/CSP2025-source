#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn];
int n,m;
bool cmp(int tx,int ty){
	return tx>ty;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i*n-n+j];
			a[i*n-n+j]=a[i*n-n+j];
		}
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			int u=(i-1)/n+1,v;
			if(u%2==0) v=u*n-i+1;
			else v=i-u*n+n;
			cout<<u<<" "<<v<<"\n";
			return 0;
		}
	}
	return 0;
}

