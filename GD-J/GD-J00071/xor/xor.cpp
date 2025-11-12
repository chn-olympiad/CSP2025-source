#include<bits/stdc++.h>
using namespace std;
long long n,k,m[500100],cnt,s[500100];
string f(long long x){
	string a="";
	while(x){
		a+=char((x%2)+'0');
		x/=2;
	}
	int l=0,r=a.size()-1;
	while(l<=r){
		swap(a[l],a[r]);
		l++,r--;
	}return a;
}
string xo(long long x,long long y){
	string a=f(x);
	string b=f(y);
	string c="";
	int len=max(a.size(),b.size());
	for(int i =0;i<len;i++){
		if(a[i]==b[i]&&a[i]=='1')c[i]='0';
		else c[i]='1';
	}return c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&m[i]);
		s[m[i]]++;
		if(m[i]!=1)f=0;
	}if(f){
		cout<<n/2;
		return 0;
	}if(k==0){
		cout<<s[0];
		return 0;
	}else if(k==1){
		cout<<s[1];
	}
	
	return 0;
}
//pr++

