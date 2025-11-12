#include<bits/stdc++.h>
using namespace std;
long long ss[800],c[800],m,n;
long long ans;
int vis[800];
long long jiecheng(int shu){
	long long ji=1;
	for(int i=1;i<=shu;i++){
		ji*=i;
		ji%=998244353;
	}
	return ji;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int sumti=0,jiti=1,jic=1;
	char linshi;
	for(int i=1;i<=n;i++){
		cin>>linshi;
		ss[i]=linshi-'0';
		sumti+=ss[i];
		jiti*=ss[i];
	}
	if(m>sumti){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		
		cin>>c[i];
		jic*=c[i];
	}
	if(jic==0&&m==n){
		cout<<0;
		return 0;
	}
	sort(c+1,c+1+n);
	if(m==n||jiti==1){
		cout<<jiecheng(n);
		return 0;
	}
	
	if(m==1){
		int loc;
		long long ans;
		for(int i=1;i<=n;i++){
			if(ss[i]==1){
				loc=i;
				break;
			}
		}
		for(int i=n;i<=n;i++){
			if(c[i]>=loc){
				ans=(n+1-i)*jiecheng(n-1);
				ans%=998244353;
				cout<<ans;
				return 0;
			}
		}
	}
	
	cout<<0;
	return 0;
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
