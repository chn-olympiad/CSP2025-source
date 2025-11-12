#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e2+10,Mod=998244353;
int n,m,c[MAXN];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>c[i];
	sort(c+1,c+1+n);
	if(m==n){
		int num=0;
		for(int i=0;i<n;i++){
			if(num>c[i])continue;
			if(s[i]=='0'){
				num++;
			}
		}
		if(num>0)cout<<"0";
		else{
			int sum=c[1],ans=1;
			for(int i=2;i<=n+1;i++){
				if(c[i]==sum){
					sum++;
				}else{
					ans=(ans*sum)%Mod;
				}
			}
			cout<<ans;
		}
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%Mod;
	}
	cout<<ans;
	return 0;
}
