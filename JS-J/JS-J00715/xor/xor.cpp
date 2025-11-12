#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c[N];
bool cmp(int x,int y){
	return x>y;
}
int yh(int x,int y){
	int a[25],b[25];
	for(int i=0;i<25;++i)a[i]=b[i]=0;
	int i=0;
	while(x>0){
		a[i]=x%2;
		++i;
		x/=2;
	}
	int j=0;
	while(y>0){
		b[j]=y%2;
		++j;
		y/=2;
	}
	int h=0;
	int t=1;
	for(int k=0;k<=max(i,j)-1;++k){
		if(a[k]!=b[k]){
			h+=t;
		}
		t*=2;
	}
	return h;
}
			
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int cnt=0;
	int value=0;
	for(int i=1;i<=n;i++){
		value=yh(value,c[i]);
		if(value==k){
			cnt++;
			value=0;
		}
	}
	cout<<cnt;
	return 0;
}
