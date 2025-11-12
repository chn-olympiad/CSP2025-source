#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
ll cot=0;
int n;
int a[5005];
void f(int p,int m,ll v){
	if(m==0){
//		cout<<v<<' '<<a[p]<<endl;// 
		if(v>2*a[p])++cot;
		return;
	}
	for(int i=p+1;i<=n;++i)
		f(i,m-1,v+a[i]);
}

ll jc(int x){
	if(x<2)return 1;
	return jc(x-1)*x;
}
ll C(int n,int m){
	return (jc(n)/jc(n-m)/jc(m)); 
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	bool flag=true;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(flag)if(a[i]!=1)flag=false;
	}
	
	if(flag){
		for(int m=3;m<=n;++m)
			cot+=C(n,m);
		cout<<cot;
		return 0;
	}
	
	sort(a+1,a+1+n);
	for(int m=3;m<=n;++m)
		for(int i=1;i<=n;++i)
			f(i,m-1,a[i]);
		
		
	cout<<cot;
	
 return 0;
}
