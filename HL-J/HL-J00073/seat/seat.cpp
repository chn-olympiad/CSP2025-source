#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,c,d;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			r=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(r%(2*n)==i || r%(2*n)==(2*n-(i-1))%(2*n)){
			c=i;
			int cnt=i;
			for(int j=1;j<=m;j++){
				if(cnt==r){
					d=j;
					cout<<d<<' '<<c;
					return 0;
				}
				if(j%2==1){
					cnt=cnt+2*n-2*i+1;				
				}
				if(j%2==0){
					cnt=cnt+(2*n-(2*n-2*i+1));
				}
			}
		}
	}
}
