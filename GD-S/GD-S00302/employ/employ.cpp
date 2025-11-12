#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],use[505];
long long ans,s[505];
string str;
void f(int x){
	if(x==n){
		if(n-s[x]>=m){
			ans++; 
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!use[i]){
			int last=s[x+1];
			use[i]=1,s[x+1]=s[x];
			if(s[x]>=a[i]||str[x]=='0')s[x+1]++;
			f(x+1);
			use[i]=0;
			s[x+1]=last;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>str;
	for(int i=1;i<=n;i++)cin>>a[i];
	f(0);
	cout<<ans;
	return 0;
} 
