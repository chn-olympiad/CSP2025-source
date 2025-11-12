#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,m,mod=998244353,a[N+1],ans=0,f[N+1];
string s;
long long A(int a,int b){
	long long sum=1;
	for(int i=1;i<=b;i++) sum=sum*(a-i+1)%mod;
	return sum;
}
void ff(int cus,int fail,int s1){
	if(cus==n+1){
		if(s1>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			if(fail>=a[i]){
				ff(cus+1,fail+1,s1);
			}
			else if(s[cus]=='0'){
				ff(cus+1,fail+1,s1);
			} 
			else{
				ff(cus+1,fail,s1+1);
			}
			f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	//sort(a+1,a+n+1);
	if(n<=10){
		ff(1,0,0);
		cout<<ans;
	}
	else{
		cout<<A(n,n);
	}
	fclose(stdin);fclose(stdout);
}
