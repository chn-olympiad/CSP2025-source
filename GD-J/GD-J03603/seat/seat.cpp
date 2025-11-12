#include<bits/stdc++.h>
using namespace std;
int n,m,t,x;//第m列 第n行 
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	int q=a[1];
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++){
		if(a[i]==q){
			t=i;//t第几名 
			break;
		}
	}
	int g=t%n,l;//g一列的第几个 l列 
	if(g==0){
		l=t/n;
	}else{
		l=t/n+1;
	}
	if(l&1==1){
		if(g==0){
			x=n;
		}else{
			x=g;
		}
	}else{
		if(g==0){
			x=1;
		}else{
			x=n+1-g;
		}
	}
	cout<<l<<" "<<x;
	return 0;
}
