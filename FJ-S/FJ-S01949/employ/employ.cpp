#include<bits/stdc++.h> 
using namespace std;
int n,m,ci;
string s;
int c[550];
long long jc(int n){
	long long sum=1;
	for(int i=1;i<=n;i++){
		sum=(sum*i)%998244353;
	}return sum; 
}
int main(){ 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)ci++;
	}if(m==n){
		bool f=1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				f=0;
			}
		}for(int i=1;i<=n;i++){
			if(c[i]==0)f=0;
		}
		if(f==0){
			cout<<0;
		}else{
			cout<<jc(n);
		}
	}else{
		cout<<jc(n-ci)*jc(ci)%998244353;
	}
	return 0;
}

