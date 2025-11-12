#include<bits/stdc++.h>
using namespace std; 
long long n,m,a[5001],b[5001],qp,ans=1;
string s;
bool flag=1;
int main(){
	freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		a[i]=s[i-1]-'0';
		if(a[i]!=1)flag=0;
		if(qp==0&&a[i]==1)qp=i;
	}
	sort(b+1,b+1+n);
	if(flag){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}else{
		if(m==n)cout<<0;//fenshu++
		else if(m==1){
			if(b[n]>=qp){
				int mmm=4;
				for(int i=n;i>=0;i--){
					if(b[i]>=qp)mmm++;
				}
				for(int i=1;i<=n-1;i++){
					ans=ans*i;
					ans%=998244353;
				}
				ans*=mmm;
				ans%=998244353;
				cout<<ans;
			}else{
				cout<<0;
			}
		}else{
			for(int i=1;i<=n-1;i++){
				ans=ans*i;
				ans%=998244353;
			}
		}
	}
	return 0;
}
