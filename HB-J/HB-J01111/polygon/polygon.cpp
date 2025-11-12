#include<bits/stdc++.h>
using namespace std;
int a[5005];
int digui(int a,int b){
	int sum=0;
	if(b!=1){
		for(int i=b-1;i<a;i++){
			sum+=digui(i,b-1);
		}
		return sum;
	}
	else return a;
}
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,p;
	cin>>n;
	if(n<=3){
		cin>>a[1]>>a[2]>>a[3];
		sort(a+1,a+4,cmp);
		int q=a[1]+a[2]+a[3];
		if(q>a[3]*2){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>p;
	}
	for(int i=3;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum+=digui(j,i);
		}
	}
	cout<<sum;
	return 0;
}
