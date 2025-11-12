#include<bits/stdc++.h>
using namespace std;
bool a=1,b=1;
long long n=0,c[505],m,cnt=0,d[505],ans,mod;
bool s[505],vis[505];
string t;
void dfs_from_1_to_2(long long deep){
	if(deep==n+1){
		long long t=0;
		for(int i=1;i<=n;++i){
			if(c[i]<=t||s[i]==0){
				++t;
				continue;
			}
		}
		if(n-t>=m)++ans;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			d[deep]=i;
			dfs_from_1_to_2(deep+1);
			vis[i]=0;
		}
	}
}void dfs_from_3_to_5(long long deep){
	if(deep==n+1){
		long long t=0;
		for(int i=1;i<=n;++i){
			if(c[i]<=t||s[i]==0){
				++t;
				continue;
			}
		}
		if(n-t>=m)++ans;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			d[deep]=i;
			dfs_from_3_to_5(deep+1);
			vis[i]=0;
		}
	}
}
void from_1_to_2(){
	dfs_from_1_to_2(1);
	cout<<ans%mod;
} 
void from_3_to_5(){
	dfs_from_3_to_5(1);
	cout<<ans%mod;
} 
void from_6_to_8(){
	ans=1;
	for(int i=2;i<=n;++i){
		ans*=i;
		ans%=mod;
	}
	cout<<ans%mod;
} 
void from_9_to_11(){
	
} 
void from_12_to_14(){
	ans=1;
	for(int i=2;i<=n;++i){
		ans*=i;
		ans%=mod;
	}
	cout<<ans%mod;
} 
void from_15(){
	for(int i=1;i<=n;++i){
		if(!s[i]){
			cout<<0;
			return;
		}
	}
	ans=1;
	for(int i=2;i<=n;++i){
		ans*=i;
		ans%=mod;
	}
	cout<<ans%mod;
} 
void from_16_to_17(){
	ans=1;
	for(int i=2;i<=n;++i){
		ans*=i;
		ans%=mod;
	}
	cout<<ans%mod;
} 
void dfs_from_18_to_21(long long d){
	
} 
void from_18_to_21(){
	if(m>18)return cout<<0,void();
	 
} 
void from_22_to_25(){
	
} 
void pan(){
	if(n<=10)from_1_to_2();
	if(n<=18&&10<n)from_3_to_5();
	if(n<=100&&18<n&&a)from_6_to_8();
	if(n<=100&&18<n&&!a)from_9_to_11();
	if(n<=500&&100<n&&m==1)from_12_to_14();
	if(n<=500&&100<n&&m==n)from_15();
	if(n<=500&&100<n&&a)from_16_to_17();
	if(n<=500&&100<n&&b)from_18_to_21();
	if(n<=500&&100<n&&!b&&!a)from_22_to_25();
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>t;
	for(int i=0;i<t.size();++i){
		s[i]=t[i]^48;
		a&=s[i];
		cnt+=s[i];
		
	}
	if(cnt>18)b=0;
	pan();
}
