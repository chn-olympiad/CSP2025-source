#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num=0,xy=0;
	cin>>n>>m;
	int a[n*m+5];
	for(int i=1;i<=n;i++) cin>>a[i];
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			if(num==a[i]){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	if(m%2==0)
		for(int i=m;i>=1;i-=2){
			for(int j=1;j<=n;j++){
				if(num==a[i]){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	else
		for(int i=m-1;i>=1;i-=2){
			for(int j=1;j<=n;j++){
				if(num==a[i]){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	return 0;
}
//行T1没输入你没输出是吧
//阴成啥了 
