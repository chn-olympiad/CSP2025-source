#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,r,a[101],st[11][11];
bool p(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,p);
	int num=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				st[j][i]=a[num];
				num++;
			}
		}else{
			for(int j=1;j<=n;j++){
				st[j][i]=a[num];
				num++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(st[j][i]==r){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}