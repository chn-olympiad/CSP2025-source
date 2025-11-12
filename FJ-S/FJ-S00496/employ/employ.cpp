#include<bits/stdc++.h>
using namespace std;
int n,m;
bool a[505];
int b[505];
long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool flag1=0,flag11=0;
	int k1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			flag1=1;
		}else{
			flag11=1;
			k1++;
		}
	}
	int k2=0;
	bool flag2=0,flag22=0;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==0){
			flag2=1;
		}else{
			flag22=1;
			k2++;
		}
	}
	if(k1<m||k2<m){
		cout<<0;
	}else if(n==m){
		if(flag1==0&&flag2==0){
			long long h=1;
			for(int i=2;i<=n;i++){
				h=h*i;
				h%=mod;
			}
			cout<<h;
		}else{
			cout<<0;
		}
	}else if(flag11==0||flag22==0){
		cout<<0;
	}else if(flag1==0){
		if(flag2==0){
			long long h=1;
			for(int i=2;i<=m;i++){
				h=h*i;
				h%=mod;
			}
			cout<<h;
		}else if(flag22==0){
			cout<<0;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
} 
