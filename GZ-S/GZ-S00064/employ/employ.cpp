#include<bits/stdc++.h>//GZ-S00064 安顺市第二高级中学 刘科 
using namespace std;
const int kMaxN=1000,MOD=998244353;
int n,m,a[kMaxN],b[kMaxN],all;
long long ans;
int C(int x,int y){//X里面选Y个 
	ans=1;
	for(int i=x,j=1;j<=y;j++,i--){
		ans=(ans*i)%MOD;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c=='1'){
			a[i]=1;
		}else{
			a[i]=0;
		}
	} 
	all=n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==0){
			all--;
		}
	}
	if(m==1){
		cout<<all%MOD<<'\n';
		return 0;
	}
	if(m>all){
		cout<<0<<'\n';
		return 0;
	}
	if(m==all){
		cout<<C(all,m)<<'\n';
		return 0;
	}
	cout<<C(all,m)<<'\n';
	return 0;
} 
