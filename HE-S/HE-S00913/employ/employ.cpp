#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],t=1,ans=1,t1;
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='1'&&t==1) t=1;
		else t=0;
		if(s[i]=='1') t1=1;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(t==1) cout<<0;
	else if(m==1&&t==0){
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans<<" ";
	}
	else if(m==n&&t1==1) cout<<0<<" ";
	else if(m==n&&t1!=1){
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	}
    fclose(stdin);
	fclose(stdout);
	return 0;
}
