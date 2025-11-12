#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],cnt,b[1001];
bool f[1001]; 
string s;
void d(int day,int give_up,int sum){
	if(day>n){
		if(sum>=m) cnt=(cnt+1)%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			if(give_up>=a[i]||b[day]==0) d(day+1,give_up+1,sum);
			else d(day+1,give_up,sum+1);
			f[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool f=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') f=0;
		b[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	f=1;
	if(f){
		long long r=1;
		for(int i=1;i<=n;i++) r=r*i;
		cout<<r%998244353;
		return 0;
	}
	d(1,0,0);
	cout<<cnt;
	return 0;
} 
