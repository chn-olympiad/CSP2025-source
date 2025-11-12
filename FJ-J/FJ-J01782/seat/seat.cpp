#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int flag=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)cout<<a[i]<<' ';
	cout<<'\n';
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				cout<<i<<' '<<j<<'\n';
				if(a[m*i-m+j]==flag){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				cout<<i<<' '<<j<<'\n';
				if(a[m*i-j+1]==flag){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
