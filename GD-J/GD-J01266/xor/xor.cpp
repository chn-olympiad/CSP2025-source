#include<bits/stdc++.h>
using namespace std;
const int N=2*10e5+5;
int a[N],n,m,sum,k,b[25],num1,num2,p,l;
bool g[1200000],c[1200000];
string s1,s2,ss;
void shier1(int x) {
	if(x==0) {
		return ;
	}
	s1=char(x%2+48)+s1;
	shier1(x/2);
	return ;
}
void shier2(int x) {
	if(x==0) {
		return ;
	}
	s2=char(x%2+48)+s2;
	shier2(x/2);
	return ;
}
int f() {
	int u,num=0;
	string s3="";
	while(s1.size()<s2.size()) {
		s1="0"+s1;
	}
	while(s2.size()<s1.size()) {
		s2="0"+s2;
	}
	for(int i=s1.size()-1; i>=0; i--) {
		if(s1[i]==s2[i])s3="0"+s3;
		else s3="1"+s3;
	}
	//cout<<s3<<' ';
	for(int i=s3.size()-1;i>=0;i--){
		num+=(s3[i]-48)*pow(2,u);
		u++;
	}
	return num;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(k==0) {
		for(int i=1; i<=n; i++) {
			if(a[i]==0)sum++,g[i]=1;
			else if(a[i-1]==a[i]&&!g[i]&&!g[i-1]) {
				sum++;
				g[i-1]=1;
				g[i]=1;
			}
		}
	} else if(k==1) {
		for(int i=1; i<=n; i++) {
			if(a[i]==1)sum++,g[i]=1;
			else {
				if(abs(a[i]-a[i-1])==1&&!g[i]&&!g[i-1]) {
					sum++;
					g[i]=1;
					g[i-1]=1;
				}
			}
		}
	} else {
		for(int i=1; i<=n; i++) {
			if(a[i]==k)sum++,g[i]=1;
			else if(i>1&&!g[i]&&!g[i-1]) {
				s1=s2="";
				shier1(a[i]);
				shier2(a[i-1]);
				l=f();
				//cout<<l<<'\n';
				if(l==k){
					sum++;
					g[i]=1;
					g[i-1]=1;
				}
				else a[i]=l;
			}
		}
	}
	cout<<sum;
	return 0;
}
