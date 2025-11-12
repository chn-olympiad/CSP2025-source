#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],t;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[(i-1)*m+j];
		}
	}
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*m+j]==t){
				if(i%2==1){
					cout<<i<<" "<<j;
				}
				else cout<<i<<" "<<n-j+1;
				return 0;
			}
		}
	}
	return 0;
}

