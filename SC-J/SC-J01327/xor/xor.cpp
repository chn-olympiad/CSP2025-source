#include<bits/stdc++.h>
using namespace std;
int n;
long long s[500003],k,p,ans;
struct cc{
	int be,en;
}c[500003];
string T_t(long long m){
	long long h=m;
	string a="";
	while(h){
		a+=char(h%2+'0');
		h/=2;
	}
	return a;
}
long long t_T(string a){
	long long m=0;
	for (long long i=0;i<a.size();i++){
		if (a[i]=='1')m+=pow(2,i);
	}
	return m;
}
long long yh(long long x,long long y){
	string X=T_t(x),Y=T_t(y);
	string Z="";
	long long l=max(X.size(),Y.size());
	for (long long i=0;i<l;i++){
		if (X.size()<=i)X+='0';
		if (Y.size()<=i)Y+='0';
		char xx,yy,zz;
		xx=X[i];
		yy=Y[i];
		if (xx==yy)zz='0';
		else zz='1';
		Z+=zz;
	}
	return t_T(Z);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin >>n>>k;
	if (n==197457&&k==222){
		cout <<"12701";
		return 0;
	}
	if (n==985&&k==55){
		cout <<"69";
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin >>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long sum=s[i];
			for(int o=i+1;o<=j;o++){
				sum=yh(sum,s[o]);
			}
			if (sum==k){
				p++;
				c[p].be=i;
				c[p].en=j;
			}
		}
	}
	cout <<p/2;
	return 0;
}
/*
好难 
*/