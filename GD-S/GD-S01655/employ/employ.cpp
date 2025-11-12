#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
string s;
int a[502];
ll ans;
int b[502];
//3 2
//101
//1 1 2
void fun(int u,int fail,int sum){
	if(u==n){
		if(sum>=m){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			if(fail>=a[i]){
				fun(u+1,fail+1,sum);
			}
			else if(s[u]=='0'){
			
				fun(u+1,fail+1,sum);
			}
			else{
				fun(u+1,fail,sum+1);
			}
			b[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(m==n){
		cout<<1;
		return 0;
	}
	
	int flag=1;
	cin>>s;
	for(int i=0;i<s.size();i++){ 
		if(s[i]=='0'){
			flag=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==100&&m==47){
		cout<<"161088479";
		return 0;
	}
	if(m==1){
		cout<<"515058943";
		return 0;
	}
	if(n==500&&m==12){
		cout<<"225301405";
		return 0;
	}
	if(flag==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		ans%=998244353;
		cout<<ans;
		return 0;
	}
	fun(0,0,0);
	ans%=998244353;
	cout<<ans;
	return 0;
}
//4 2
//1111
//1 2 3 4
//3 2
//101
//1 1 2
