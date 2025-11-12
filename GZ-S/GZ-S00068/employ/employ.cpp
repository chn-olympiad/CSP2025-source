//GZ-S00068 北京师范大学贵阳附属中学 刘雨航 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,c[501]={},ans,t=0;
	const long long U=998244353;
	string sb;
	bool s[501]={};
	cin>>n>>m;
	cin>>sb;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	} 
	for(int i=1;i<=sb.size();i++){
		s[i]=sb[i];
		if(s[i]==1)t++;
	} 
	if(m!=1){
		ans=1;
		for(int i=m;i>=2;i--){
		ans*=i;}
		cout<<ans%U;
	}else{
		ans=1;
		for(int i=t;i>=2;i--)ans*=i;
		cout<<ans%U;
	}
	return 0;
}
