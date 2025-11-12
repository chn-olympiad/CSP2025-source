#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
long long int n,m,p[510],cun = 0,bq = 998244353,cnt = 0,ans = 1;
string q;
cin>>n>>m;
cin>>q;
for(int i = 1;i<=n;i++){
	cin>>p[i];
}
for(int i = 0;i<q.size();i++){
	if(q[i]=='1')cun++;
	if(q[i]=='0')cnt++;
}
if(cun==q.size()){
	for(int i = 2;i<=n;i++){
		ans*=i;
		ans%=bq;
	}
	cout<<ans;
	return 0;
}else if(cnt>=1&&n==m){
	cout<<0;
	return 0;
}else if(cnt==0&&n==m){
	for(int i = 2;i<=n;i++){
		ans*=i;
		ans%=bq;
	}
	cout<<ans;
	return 0;
}else if(cnt==n){
	cout<<0;
	return 0;
}else if(m==1){
	for(int i = 2;i<=n;i++){
		ans*=i;
		ans%=bq;
	}
	cout<<ans;
	return 0;	
}
return 0;
}
