#include <bits/stdc++.h>
using namespace std;
int a[500005];
string zhuan1(int n){
	string x,y;
	while (n>0){
		x+=n%2;
		n/=2;
	}
	for (int i=x.length()-1;i>=0;i--){
		y+=x[i];
	}
	return y;
}
int zhuan2(string n){
	int x=0;
	int ans=1;
	for (int i=n.length()-1;i>=0;i--){
		x+=n[i]*ans;
		ans*=2;
	}
	return x;
}
string bu(string n,int m){
	string x;
	int cnt=0;
	for (int i=0;i<m;i++){
		if (m-n.length()>0){
			x+='0';
		}
		else{
			x+=n[cnt++];
		}
	}
	return x;
}
int xo(int x,int y){
	string n=zhuan1(x);
	string m=zhuan1(y);
	string l;
	n=bu(n,max(n.length(),m.length()));
	m=bu(m,max(n.length(),m.length()));
	for (int i=0;i<n.length();i++){
		if (n[i]==m[i]){
			l+='0';
		}
		else{
			l+='1';
		}
	}
	return zhuan2(l);
}
int main(){
	int n,k,sum=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int left=1,right=1;
	while(true){
		if (left==right&&a[left]==k){
			sum++;
			left++;
			right++;
		}
		else{
			right++;
		}
	}
	return 0;
}
