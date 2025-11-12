#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
long long n,m,c[505],a[505];
string s;
long long jc(long long x){
	long long ans=1;
	for(int i=2;i<=x;i++) ans=(ans*i)%Mod;
	return ans;
}
void work1(){
	bool flag=1;
	for(int i=0;i<n;i++)
		if(s[i]=='0') flag=0;
	if(flag) cout<<jc(n);
	else cout<<0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	cout<<jc(100)<<endl;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		a[i]=i;
	}
	if(m==n){
		work1();
		return 0;
	}
	bool flag=1;
	for(int i=0;i<n;i++)
		if(s[i]=='0') flag=0;
	if(flag){
		cout<<jc(n);
		return 0;
	}
	if(n<=100){
		long long ans=0;
		do{
//			cout<<1<<endl;
			long long cnt=0;
			for(int i=1;i<=n;i++){
				if(cnt>=c[a[i]]){
					cnt++;
					continue;
				}else if(s[i-1]=='0'){
					cnt++;
				}
			}
			if((n-cnt)>=m){
				ans=(ans+1)%Mod;
			}
		}while(next_permutation(a+1,a+1+n));
		cout<<ans<<endl;
		return 0;
	}
	cout<<0;
	return 0;
}
