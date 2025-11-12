#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,zr,a[105]={},zj=0;
	cin>>m>>n;
		for(int i=1;i<=m*n;i++){
			cin>>a[i];
		}
		zr=a[1];
		sort(a,a+m*n,cmp);
		for(int i=1;i<=m*n;i++){
			if(a[i]==zr){
				zj=i+1;
				break;
			}
		}
		if(zj<=m){
			cout<<"1"<<" "<<zj;
		}else if(zj>m){								
				cout<<zj/m+1<<" "<<zj%m;		
		}
	return 0;
}
