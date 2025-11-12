#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,len[200100];
string s1[200100],s2[200100],t1,t2;
bool b[1000010];
void work1(){
	while(q--){
		cin>>t1>>t2;
		int ans=0;
		int lent=t1.length();
		b[lent]=1;
		for(int i=lent-1;i>=0;i--)
			b[i]=(b[i+1] && t1[i]==t2[i]);
		for(int i=0;i<lent;i++){
			if(i>0 && t1[i-1]!=t2[i-1]) break;
			for(int j=1;j<=n;j++){
				bool flag=true;
				if(i+len[j]-1>=lent) continue;
				for(int k=0;k<len[j];k++){
					if(s1[j][k]!=t1[i+k] || s2[j][k]!=t2[i+k]){
						flag=false;
						break;
					}
				}
				if(flag && b[i+len[j]]) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
void work2(){
	int bpos[100010],bz[100010];
	for(int i=1;i<=n;i++){
		for(int j=0;j<len[i];j++)
			if(s1[i][j]=='b') bpos[i]=j;
		for(int j=0;j<len[i];j++)
			if(s2[i][j]=='b') bz[i]=j-bpos[i];
	}
	while(q--){
		cin>>t1>>t2;
		int lent=t1.length();
		int tpos,tz;
		for(int j=0;j<lent;j++)
			if(t1[j]=='b') tpos=j;
		for(int j=0;j<lent;j++)
			if(t2[j]=='b') tz=j-tpos;
		int ans=0;
		for(int i=1;i<=n;i++)
			if(tpos>=bpos[i] && bz[i]==tz && lent-tpos>=len[i]-bpos[i]) ans++;
		cout<<ans<<'\n';
	}
}
signed main(){
	std::ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int sum=0;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i],
		len[i]=s1[i].length(),
		sum+=len[i];
	if(n<=1000 && sum<=2000) work1();
	else work2();
	return 0;
}
