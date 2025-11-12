#include<bits/stdc++.h>
using namespace std;

int f(int n){
	int m[10],v=0;
	while(n){
		v++;
		m[v]=n%2;
		n/=2;
	}
	int a=0;
	for(int i=v;i>=1;i--){
		a=a*10+m[i];
	}
	return a;
}

int cnm(int n,int m){
	int a[10]={0,0,0,0,0,0,0,0,0,0},aa=0;
	int b[10]={0,0,0,0,0,0,0,0,0,0},bb=0;
	if(n==0) return m;
	if(m==0) return n; 
	if(n==1&&m==1) return 0;
	while(n){
		a[aa]=n%10;
		n/=10;
		aa++;
	}
	while(m){
		b[bb]=m%10;
		m/=10;
		bb++;
	}
	for(int i=0;i<=10;i++){
		if(a[i]==b[i]) a[i]=0;
		else a[i]=1;
	}
	int t=0;
	for(int i=9;i>=0;i--){
		t=t*10+a[i];
	}
	return t;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s[500005],t=0;
	cin>>n>>k;
	k=f(k);
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		s[i]=f(a);
	}
	
	for(int j=0;j<=n;j++){
		int l=0,tt=0,v=0;
		while(v<=n){
		v+=l;
		l=0;
		int a=0;
		for(int i=1;i<=j&&v+i<=n;i++){
			a=cnm(s[i+v],a);
			if(a==k){
				l=i-1;
				tt++;
				break;
			}
		}
		l++;
		}
	t=max(t,tt);
	if(2*tt<t) break;
	}
	cout<<t;
	return 0;
}

