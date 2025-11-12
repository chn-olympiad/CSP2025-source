#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,rj=0;
	cin>>n>>m; 
	int z[n][m]={0};
	int a[n*m]={0};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			rj=a[i];
		}
	}
	for(int i=1;i<=n*m;i++){
		//排序
		if(i!=1){
			if(a[i-1]<a[i]){
				int tmp=a[i-1];
				a[i-1]=a[i];
				a[i]=tmp;
			}
		} 
	}
	int c,r;
	for(int i=1;i<=n*m;i++){
		if(a[i]==rj){
			//如果他是最后一个 
			if(i==n*m){
				c=m;
				r=1;
				cout<<c<<" "<<r;
				return 0;
			} 
			//如果不是，求他座位的行数和列数
		}
	} 
	
	
	return 0;
}
