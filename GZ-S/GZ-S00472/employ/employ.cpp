//GZ-S00472 遵义市南白中学 陈梓睿
#include<bits/stdc++.h>
#define ll long long
#define M 998244353
using namespace std;
int n,m;
string a;
int qw[505];
ll sum = 1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i = 0;i<n;i++){
		cin>>qw[i];
	}
	bool f = 1;
	for(int i = 0;i<n;i++){
		if(a[i]=='0') f = 0;
	}
	if(m==n){
		for(int i = 0;i<n;i++){
			if(a[i]=='0'){
				cout<<"0\n";
				return 0;
			} 
		}
		for(int i = 0;i<n;i++){
			if(qw[i]==0){
				cout<<"0\n";
				return 0;
			}
		}
		cout<<"1\n";
	}else if(f){
		int cnt;
		for(int i = 0;i<n;i++){
			if(qw[i]==0){
				cnt++;
			}
		}
		if(n-cnt>m){
			cout<<"0\n";
		}else if(n-cnt==m){
			for(int i = 1;i<=m;i++) sum*=i,sum%=M;
			cout<<sum;
		}else{
			for(int i = 1;i<=m;i++) sum*=i,sum%=M;
			cout<<sum;
		}
	}else if(m==1){
		bool fl = 0;
		for(int i = 0;i<n;i++){
			if(a[i]!='0'){
				fl = 1;
			} 
		}
		bool fla = 0;
		int u=  0;
		for(int i = 0;i<n;i++){
			if(qw[i]!=0){
				fla=1;
				u++;
			}
		}
		if(fla&&fl){
			for(int i = 0;i<n;i++){
				ll he = u;
				if(a[i]!=0){
					he = u;
					for(int j = i+2;j<=n;j++) he*=j,he%=M;
				}
				sum+=he,sum%=M;
			}
			
		}
		cout<<sum;
	}else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

