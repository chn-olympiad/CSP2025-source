#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e4+10;
int a[N];
int xia;
int lie,hang;
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
	int r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			xia=i;
			break;
		}
	}
	if(xia%n==0){
		lie=xia/n;
		cout<<lie<<" ";
	}
	else{
		lie=xia/n+1;
		cout<<lie<<" ";
	}
	if(lie%2==1){
		hang=xia%n;
		if(hang==0) hang=n;
		cout<<hang<<" ";
	}
	else{
		int k=xia%n;
		if(k==0) k=n;
		hang=n-k+1;
		cout<<hang<<" ";
	}
	return 0;
}
