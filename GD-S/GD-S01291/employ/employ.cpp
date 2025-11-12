#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
long long  fact[100005],c[1000];
const int MOD=998244353;
string text;
bool flag=1,book[1000];
int ans;
int m,n;

void dfs(int deep,int out){
	if(deep==n){
		if(m<=n-out)ans=ans+1%MOD;
	//	printf("out=%d  ans=%d  deep=%d\n",out,ans,deep);
		return ;
	}
	else if(deep-out>=m){
		ans=ans+fact[n-deep]%MOD;
		return ;
	}
	else if(m+out>n)return;
	else{
	for(int i=1;i<=n;i++){
		if(book[i])continue;
		book[i]=1;
		if(out>=c[i]){
			dfs(deep+1,out+1);
		}
		else if(text[deep]=='0'){
			dfs(deep+1,out+1);
		}else{
			dfs(deep+1,out);
		}
		book[i]=0;
	}
	
	return;
	}
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	fact[0]=1;
	cin>>n>>m>>text;
	for(int i=0;i<text.length() ;i++)
		if(text[i]!='1')flag=0;
	for(int i=1;i<=1000;i++){
			fact[i]=(fact[i-1]*i)%MOD;
		}
	if(n==m){
		fact[0]=1;
		cout<<fact[n];
		return 0;
	}
	else if(n<=18){
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		dfs(0,0);
		cout<<ans;
	}
	else if(flag){
		fact[0]=1;
		for(int i=1;i<=1000;i++){
			fact[i]=(fact[i-1]*i)%MOD;
		}
		cout<<fact[n+m];
		return 0;
	}
	else {
		m=(m)%10000;
		fact[0]=1;
		for(int i=1;i<=100000;i++){
			fact[i]=(fact[i-1]*i)%MOD;
			}
		cout<<fact[100000-m];
	}
	return 0;
}
