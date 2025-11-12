#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int t,tot;

bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++tot];
		}
	}
	t=a[1];
	sort(a+1,a+1+tot,cmp);
	int mi,mj;
	for(int i=1;i<=tot;i++){
		if(a[i]==t){
			int mi=ceil(1.0*i/n);
			cout<<mi<<" ";
			int mj=i%n;
			if(mj==0)mj=n;
			if(mi%2==1){
				cout<<mj;
			}
			else{
				cout<<n-mj+1;
			}
			break;
		}
	}
	return 0;
}
/*
	2 2
	98 99 100 97
*/
