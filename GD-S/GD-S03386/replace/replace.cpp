#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=5e6+9;
#define ull unsigned long long 
int n,q;
string s1,s2,t1,t2;
ull h1[maxn],h2[maxn];
ull a[maxn],b[maxn],l[maxn],p[maxn];
ull has(string s){ 
	ull cn=0;
	for(int i=0;i<s.length();i++){
		cn+=(s[i]-'a'+1)*p[i];
	}
	return cn;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<10;i++){
		p[i]=p[i-1]*17;
		p[i]%=mod;
	}
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		l[i]=s1.length();
		h1[i]=has(s1);
		h2[i]=has(s2);
//		cout<<h1[i]<<" "<<h2[i]<<endl;
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int t1l=t1.length(),t2l=t2.length();
		for(int i=0;i<t1l;i++){
			if(i==0)a[i]=t1[i]-'a'+1;
			else a[i]=a[i-1]+(t1[i]-'a'+1)*p[i];
//			cout<<a[i]<<" ";
		}
//		cout<<endl;
		for(int i=0;i<t2l;i++){
			if(i==0)b[i]=t2[i]-'a'+1;
			else b[i]=b[i-1]+(t2[i]-'a'+1)*p[i];
//			cout<<b[i]<<" ";
		}
//		cout<<endl;
		int ans=0;
		for(int i=0;i<t1.length();i++){
			for(int j=1;j<=n;j++){
				if((a[i+l[j]-1]-a[i-1])==h1[j]*p[i]&&(b[i+l[j]-1]-b[i-1])==h2[j]*p[i]&&a[i-1]==b[i-1]&&a[t1l-1]-a[i+l[j]-1]==b[t2l-1]-b[i+l[j]-1])ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
