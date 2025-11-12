#include<bits/stdc++.h>
using namespace std;
const long long mo=9980244353;
int n,m,c[512];
long long ans,cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==0) cnt++;
	}
	int flag=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') flag++;
	}
	if(n-flag<m){
		cout<<0;
		return 0;
	} 
	ans=1;
	for(int i=n-cnt;i>=n-m-cnt+1;i--){
		ans=(ans*i)%mo;
	}
	
	cout<<max(ans,0*1ll)<<endl;
	return 0;
}