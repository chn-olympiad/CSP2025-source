#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
int p[N],p2[N];
int sum[N],sm[N];
void getpi(string s,int pi[N]){
	for(int i=1;i<s.size();i++){
		int len=pi[i-1];
		while(len&&s[len]!=s[i])len=pi[len-1];
		pi[i]=len+(s[len]==s[i]);
	}
}
void work(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		sum[0]=1,sm[t1.size()+1]=1;
		for(int i=0;i<t1.size();i++){sum[i+1]=sm[i+1]=0;}
		for(int i=0;i<t1.size();i++){if(t1[i]!=t2[i])break;sum[i+1]=1;}
		for(int i=t1.size()-1;i>=0;i--){if(t1[i]!=t2[i])break;sm[i+1]=1;}
		int ans=0;
		for(int i=1;i<=n;i++){
			getpi(s1[i]+'#'+t1,p);
			getpi(s2[i]+'#'+t2,p2);
			int sz=s1[i].size();
			for(int j=sz+1,jj=0;j<sz+1+t1.size();j++,jj++){
				if(p[j]==sz&&p2[j]==sz&&sum[jj-sz+1]&&sm[jj+2]){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
void clear(){}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int _=1;
	while(_--)work(),clear();
	return 0;
} 
