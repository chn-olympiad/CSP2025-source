#include<bits/stdc++.h>
#include<cmath>
using namespace std;
const int N=5*100000+50;
long long n,k,sum=0;
long long b[N];
string a[N],k1;

string f(long long n){
	string m,s;
	while(n>1){
		if(n%2==0){
			m=m+'0';
			n=n/2;
		}
		else{
			m=m+'1';
			n=(n+1)/2;
		}
	}
	m=m+'1';
	for(int i=m.size()-1;i>=0;i--){
		s=s+m[i];
	}
	return s;
}

string anhuo(string n,string m){
	string s,s1;
	int sum=max(n.size(),m.size());
	for(int i=0;i<sum;i++){
		if(n[i]!='1')	n[i]='0';
		if(m[i]!='1')	m[i]='0';
		if(n[i]==m[i]&&n[i]=='0')	s=s+'1';
		else s=s+'0';
	}
	while(sum>1&&s[sum-1]=='0'){
		sum--;
	}
	for(int i=sum-1;i>=0;i--){
		s1=s1+s[i];
	}
	return s1;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		a[i]=f(b[i]);
	}
	k1=f(k);
	for(int i=1;i<=n;i++){
		if(anhuo(a[i],a[i])==k1)	sum++;
	}
	cout<<sum;
	return 0;
}