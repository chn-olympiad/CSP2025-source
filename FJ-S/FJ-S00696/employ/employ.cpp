#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std; 
const int mod=998244353;
int n,m;
string s;
int c[100100];
int js(int n){
	int s=1;
	for(int i=1;i<=n;i++){
		s*=i;
		s%=mod;
	}
	return s;
}
int v[100100],ans;
void moni(string t){
	int res=0;
	for(int i=0;i<n;i++){
		if(i+1-res>=c[i]){
			continue;
		}
		if(s[i]){
			res++;
		}
	}
	if(res>=m){
		ans++;
	}
}
void dfs(int k,string str){
	if(k>n){
		moni(str);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			dfs(k+1,str+char(i)); 
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=1){
			f=0;
		}
	}
	if(f==1){
		cout<<js(n);
		return 0;
	}else if(m==1){
		int ss=0,p=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				p=i+1;
				break;
			}
		}
		if(p==0){
			cout<<0;
			return 0;
		}		
		for(int i=1;i<=n;i++){
			if(c[i]>p){
				ss++;
			}
		}
		cout<<ss*js(n-1)%mod;
		return 0;
	}else if(m==n){
		int ff=1;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				ff=0;
				break;
			}
		}
		if(ff){
			cout<<js(n);
		}else{
			cout<<0;
		}
		return 0;
	}else{
		dfs(1,"");
		cout<<ans;
	}
	return 0;
}
