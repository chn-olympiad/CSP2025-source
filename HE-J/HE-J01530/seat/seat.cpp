#include<bits/stdc++.h>
using namespace std;
int a[1001];
bool cmp(int x,int y){
	if(x>y)return true;
	else return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int z=a[1];
	sort(a+1,a+1+m*n,cmp);
	int zn=-1;
	for(int i=1;i<=m*n;i++){
		if(a[i]==z){
			zn=i;
			break;
		}
	}
	int m1=ceil(float(zn)/float(m)),n1;
	if(zn%(2*n)>n){
		n1=n-(zn%(2*n)%n)+1;
	}
	else{
		n1=zn%(2*n);
	}
	cout<<m1<<' '<<n1;
	return 0;
}
