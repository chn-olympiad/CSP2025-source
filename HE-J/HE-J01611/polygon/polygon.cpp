#include <bits/stdc++.h>
using namespace std;
int de(int c){
	if(c==1){
	return 1;
	}
	return c*de(c-1);
}int maxt(int q[t]){
	int ma=-1;
	for(int i=0;i<t;i++){
		ma=max(ma,q[i]);
	}return ma;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int r;
	cin>>r;
	int a[r];
	long long b=0;
	for(int i=0;i<r;i++){
		cin>>a[i];
	}for(int i=3;i<=r;i++){
		int x=0;
		int y=de(r)/de(i)
		b+=2;
	}cout<<b% 998244353;
	return 0;
}//buxixi
//·ë¡¤ÅµÒÀÂü help
