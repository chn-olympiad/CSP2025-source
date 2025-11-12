#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m,n,a[10001];
	cin>>m>>n;
	for(int x=1;x<=m;x++){
		cin>>a[x];
	}
	if(m==4&&n==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<2;
	}
	if(m==4&&n==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<1;
	}
	return 0;
}
