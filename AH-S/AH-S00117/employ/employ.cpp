#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0,sum=0,ans=1,c[509],w=0,p=998244353,x[509],f[509],ymy=0;string s;
void A(long long h){
	if(h>n){
		int u=0,ccnt=0;
		for(int i=1;i<=n;i++){
			if(c[f[i]]<=u) u++;
			else{
				if(s[f[i]]=='0') u++;
				else ccnt++;
			}
		}
		if(ccnt>=m) ymy++;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(x[i]==0) x[i]=1,f[h]=i,A(h+1),x[i]=0,f[h]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) sum++;
	}
	for(int i=0;i<n;i++)
		if(s[i]=='1') cnt++,w=max(w,c[i+1]);
	if(cnt==n){
		for(int i=1;i<=n;i++) ans=ans*i%p;
		cout<<ans%p;return 0;
	}
	if(m==1){
		if(cnt==0){cout<<0;return 0;}
		ans*=w;
		for(int i=1;i<n;i++) ans=ans*i%p;
		cout<<ans;return 0;
	}
	if(n==m){
		if(cnt!=n||sum!=0) cout<<0;
		else{
			for(int i=1;i<=n;i++) ans=ans*i%p;
			cout<<ans%p;
		}
		return 0;
	}
	if(m>cnt){cout<<0;return 0;}
	A(1);cout<<ymy;return 0;
}
