#include<bits/stdc++.h>
using namespace std;
int n,k,s[500001],t[2000001][2],v[2000001][2],ans,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]^=s[i-1];
		if(s[i]==k){
			ans++;
			s[i]=cnt=0;
			continue;
		}
		bool f=1;
		for(int j=20,p=0;j>=0;j--){
			int x=(s[i]>>j)&1,y=(k>>j)&1;
			if(t[p][x^y]&&(v[p][x^y]==ans+1))p=t[p][x^y];
			else{
				f=0;
				break;
			}
		}
		if(f){
			ans++;
			s[i]=cnt=0;
			continue;
		}
		for(int j=20,p=0;j>=0;j--){
			int x=(s[i]>>j)&1;
			if((!t[p][x])||(v[p][x]!=ans+1)){
				v[p][x]=ans+1;
				t[p][x]=++cnt;
			}
			p=t[p][x];
		}
	}
	cout<<ans;
}
