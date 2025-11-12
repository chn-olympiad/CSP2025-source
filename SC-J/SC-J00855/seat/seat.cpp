#include<bits/stdc++.h>
using namespace std;
//先行后列 
int a[120];
bool cmp(int a,int b){
	if(a>b)return 1;
	else return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1];
	sort(a+1,a+1+n*m,cmp);
	int num=1;
	while(a[num]!=k) num++;
	int lun=num%(2*n),luns=num/(2*n);
	if(lun==0){
		cout<<luns*2<<" "<<1;
	}
	else if(lun<=n){
		cout<<luns*2+1<<" "<<lun;
	}else{
		lun-=n;
		cout<<luns*2+2<<" "<<n+1-lun;
	}
	return 0;
}