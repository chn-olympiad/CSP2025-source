#include<bits/stdc++.h>
using namespace std;
int n,m;
int fenshu[1145];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&fenshu[i]);
	}
	int xiaoR=fenshu[1];
	sort(fenshu+1,fenshu+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(fenshu[i]==xiaoR){
			float c=(i*1.0)/(n*1.0);cout<<int(ceil(c))<<' ';
			int r=i%n;
			if(r==0)cout<<n;
			else if(int(ceil(c))%2)cout<<r;
			else cout<<n-r+1;
		}
	}
	return 0;
}
