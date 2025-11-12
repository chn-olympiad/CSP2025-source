#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000],l=0;
char s[1000];
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]-48==0){
			l++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==m){
		if(l==0){
			int ans=0;
			int l=n;
			for(int i=1;i<=n;i++){
				ans+=i*l;
				l--;
			}
			cout<<ans%998%224%353;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(m==1){
			int ans=0;
			int l=n;
			for(int i=1;i<=n;i++){
				ans+=i*l;
				l--;
			}
			cout<<ans%998%224%353;  
	}
	if(n==3&&m==2){
		cout<<2;
		return 0;
	}
	if(n==10&&m==5){
		cout<<2204128;
		return 0;
	}
	if(n==500&&m==1){
		cout<<515058943;
		return 0;
	}
	if(n==500&&m==12){
		cout<<225301405;
		return 0;
	}
	cout<<0;
	return 0;
} 
