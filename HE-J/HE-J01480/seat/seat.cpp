#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int ren=n*m;
	for(int i=1;i<=ren;i++){
		cin>>a[i];
	}
	int r=a[1];
	int weizhi;
	sort(a+1,a+1+ren,cmp);
	for(int i=1;i<=ren;i++){
		if (a[i]==r){
			weizhi=i;
		}
	}
	int lie=ceil(double((double)weizhi/(double)n));
	cout<<lie<<" ";
	int hang=weizhi-(lie-1)*n;
	if (lie%2!=0){
		cout<<hang;
	}else{
		cout<<n-hang+1;
	}
	return 0;
}
