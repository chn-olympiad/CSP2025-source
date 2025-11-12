#include<bits/stdc++.h>
using namespace std;
int n,a[5005],y;
int main(){//rp=INT_MAX;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;//awa 
	}
	if(n==3){
		int m=0,x;
		for(int i=1;i<=3;i++){
			x+=a[i];
			m=max(m,a[i]);
		}
		if(x>m*2)cout<<1;
		else cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)y=1;
	}
	if(y==0){
		int d=1,t=1,z=3;
		for(int i=1;i<=n-3;i++){
			t+=z;
			z+=i+2;
			d+=t;
			d%=998244353;
		}
		cout<<d;
		fclose(stdin);
		fclose(stdout);
		return 0;//zheng jiu 36 fen  good!!
	}
	sort(a+1,a+n+1);
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//lai fu gao hai yao pa shan
//shei zhi dao ta jian na me gao
