#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+100,mod=1e9+7;
int n,q;
ll mi[N],hs1[N],hs2[N]; 
map<int,int> mp;
int Hash(string &s){
	int res=0;
	for(int i=0;i<s.size();i++)
		res=(res*27%mod+s[i]-'a'+1)%mod;
	return res;
}
void fact(){
	mi[0]=1;
	for(int i=1;i<=5e6;i++)
		mi[i]=mi[i-1]*27%mod;
}
int pin(int A,int B,int len){
	return (A*mi[len]%mod+B)%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	fact();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[pin(Hash(s1),Hash(s2),s1.size())]++;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size(),s=0,L=1,R=len,ans=0;
		s1='#'+s1,s2='#'+s2;
		for(int i=1;i<=len;i++){
			hs1[i]=(hs1[i-1]*27%mod+s1[i]-'a'+1)%mod;
			hs2[i]=(hs2[i-1]*27%mod+s2[i]-'a'+1)%mod;
		}
		for(;L<len;L++)
			if(s1[L]!=s2[L]) break;
		for(;R>=0;R--)
			if(s1[R]!=s2[R]) break;
		for(int i=R;i<=len;i++){
			for(int j=L;j>=1;j--)
				ans+=mp[pin(hs1[i]-hs1[j-1]*mi[i-j+1],hs2[i]-hs2[j-1]*mi[i-j+1],i-j+1)];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*

*/
