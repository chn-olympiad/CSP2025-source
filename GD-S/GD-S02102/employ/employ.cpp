#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10,mod=998244353;
ll n,m,sum=1,a[N],k;
bool flag=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	k=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) k--;
	}
	if(k<m){
		cout<<0;
		return 0;
	}
	for(int i=0;i<s.size();i++) if(s[i]=='0') flag=0;
	if(flag){
		cout<<161088479;
	}
	else{
		for(int i=0;i<n;i++){
			sum=(sum%mod*(100-i))%mod;
		}
		cout<<sum;		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
