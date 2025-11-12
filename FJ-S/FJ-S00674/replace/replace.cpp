#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005],t1,t2;
void solve(){
	int len1=t1.length(),len2=t2.length();
	long long ans=0;
	if(len1!=len2){
		cout<<0<<"\n";
		return;	
	}
	for(int i=0;i<len1;i++){
		for(int j=1;j<=n;j++){
			bool flag=1;
			if(i+s1[j].length()>len1) continue;
			for(int k=0;k<s1[j].length();k++){
				if(t1[i+k]!=s1[j][k]||t2[i+k]!=s2[j][k]){
					flag=0;break;
				}
			} 
			for(int k=i+s1[j].length();k<t1.length();k++){
				if(t1[k]!=t2[k]){
					flag=0;break;
				}
			}
			if(flag) ans++;
		}
		if(t1[i]!=t2[i]) break;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		solve();
	}
}
