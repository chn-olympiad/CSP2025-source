#include<bits/stdc++.h>
using namespace std;
int n,m;
int id;
int a[100005];
int ii,jj;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sum=a[1];
	sort(a+1,a+1+n*m,cmp);

	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			id=i;
		}
	}
	//cout<<id;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			id--;
			if(id==0){
				ii=i;
				jj=j;
			}
		}
	}
	cout<<ii<<" ";
	if(ii%2==0){
		cout<<n-jj+1<<" ";
	}
	else{
		cout<<jj<<" ";
	}
	return 0;
}
