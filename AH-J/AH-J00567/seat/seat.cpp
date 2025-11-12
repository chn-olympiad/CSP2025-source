#include<bits/stdc++.h>
using namespace std;
int n,m,bj,x,y;
int a[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int t=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);

	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			bj=i;
		}
	}
	x=bj/(2*n);//zu
	y=bj%(2*n);//weizhi
	if(y>n){
		x=(1+x)*2;
		y=2*n-y+1;
	}
	else{
		x=(1+x)*2-1;
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
