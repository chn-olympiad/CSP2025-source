#include<bits/stdc++.h>
using namespace std;

struct _2{int n[22]={0},l=0;};

void _2out(_2 n){
	for(int i=n.l-1;i>=0;--i)cout<<n.n[i];
	cout<<"\n"; 
}

_2 _10to_2(int n){
	_2 n2;
	while(n>0)n2.n[n2.l]=n%2,n2.l++,n/=2;
	return n2;
}

_2 xor_2(_2 a,_2 b){
	_2 c;
	for(int i=(a.l>=b.l?a.l:b.l)-1;i>=0;--i)c.n[i]=(a.n[i]+b.n[i])%2,c.l++;
	return c;
}

int _2to_10(_2 n2){
	int n=0;
	for(int i=n2.l-1;i>=0;--i)n=n*2+n2.n[i];
	return n;
}

int xor10(int a,int b){
	_2 a2=_10to_2(a),b2=_10to_2(b),c=xor_2(a2,b2);
	return _2to_10(c);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,X[500055];
	cin>>n>>k;
	for(int i=0;i<n;++i)cin>>X[i];
	if(n<=200000 && k==0){
		int s=0,z=0;
		for(int i=0;i<n;++i){
			if(X[i]==1&&z==0)z=1;
			else if(X[i]==1&&z==1)s++,z=0;
			else if(X[i]==0&&z==0)s++;
		}
		cout<<s;
	}
	else if(n<=200000 && k==1){
		int s=0,z=0;
		for(int i=0;i<n;++i){
			if(X[i]==0&&z==0)z=1;
			else if(X[i]==1&&z==1)s++,z=0;
			else if(X[i]==1&&z==0)s++;
		}
		cout<<s;
	}
}

/*
1 0 1 0 0 1 1 1 0 0
0 1 0 1 1 0 0 0 1 1
*/
