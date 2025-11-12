#include<bits/stdc++.h>
using namespace std;
const int N=200010;
string s1[N],s2[N];
string s,t;
int n,q,si[N];
void doit(){
	cin>>s>>t;
	int l=0,r=s.size()-1;
	while(s[l]==t[l])l++;
	while(s[r]==t[r])r--;
	int len=r-l+1;
	int ans=0;
	int ss=s.size();
	string fr="",to="";
	for(int i=l;i<=r;i++)fr+=s[i],to+=s[i];
	for(int i=1;i<=n;i++){
		if(si[i]<len)continue;
		int wz=-1;
		while((wz=s1[i].find(fr,wz+1))!=-1){
			bool pd=1;
			if(l<wz)continue;
			if(si[i]-(wz+len)>ss-r-1)continue;
			for(int j=l,b=wz;j<=r;j++,b++){
				if(t[j]!=s2[i][b]){
					pd=0;break;
				}
			}
			if(!pd)continue;
			for(int j=l-wz,b=0;j<l;j++,b++){
				if(s[j]!=s1[i][b]){
					pd=0;break;
				}
				if(t[j]!=s2[i][b]){
					pd=0;break;
				}
			}
			if(!pd)continue;
			for(int j=r+1,b=wz+len;b<si[i];j++,b++){
				if(s[j]!=s1[i][b]){
					pd=0;break;
				}
				if(t[j]!=s2[i][b]){
					pd=0;break;
				}
			}
			if(!pd)continue;
			ans++;
		}
	}cout<<ans<<'\n';
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i],si[i]=s1[i].size();
	while(q--)doit();
}
/*c c f wo cao ni ma*/
