#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010];
int s(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+x,s);
	for(int i=1;i<=x;i++){
		if(a[i]==r){
			if(m==1){
				cout<<i<<' '<<1;
			}else if(n==1){
				cout<<1<<' '<<i;
			}
		}
	}
	return 0;
}
