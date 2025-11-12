#include<bits/stdc++.h>
using namespace std;
int xx=998244353;
long long t=0;
int a[5005];
int n;
void f(int x,int y){
	int tt=a[y]+a[y+1];
	for(int i=y+1;i<=n-i+1;i++){
		if(tt>=i){
			t++;
			t%x;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<+n;i++){
	cin>>a[i];
}
for(int i=2;i<=n-1;i++){
	for(int j=1;j<=n-i+1;j++){
		f(i,j);
	}
}
cout<<t;
}
