#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int m,n,k;
int a[101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==k){
			int u=i%(2*m);
			if(u==0){
				int v=i/m;
				cout<<v<<" "<<0;
				return 0;
			}
			int v=i/m;
			if(u<m){
				cout<<v+1<<" "<<u;
				return 0;
			}
			if(u==m){
				cout<<v<<" "<<u;
				return 0;
			}
			cout<<v+1<<" "<<n-(u-m)+1;
			return 0;
		}
	}
	return 0;
}
