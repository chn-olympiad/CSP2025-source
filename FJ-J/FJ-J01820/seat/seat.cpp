#include<bits/stdc++.h>
using namespace std;
int a[100+5],sum[20+5];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,num;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			num=i;
		}
	}
	for(int i=1;i<=m;i++){
		sum[i]=i;
		sum[m+i]=m-i+1;
	}
	cout<<(num-1)/n+1<<' '<<sum[num%(2*m)];
	return 0;
}
