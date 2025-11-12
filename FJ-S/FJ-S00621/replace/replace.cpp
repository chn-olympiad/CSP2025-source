#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int M=5e6+5;
string s,t;
string s1[N],s2[N];
int id1[N],id2[N];
int n,q,m,ans,pos1,pos2;
int cnt;
bool flag=1;
int nxt1[M],nxt2[M];
int cnt1[M];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		cnt=0;
		for(int j=0;j<s1[i].size()&&flag;j++){
			if(s1[i][j]=='b') cnt++,pos1=j;
			else if(s1[i][j]!='a') flag=0;
			if(cnt>1) flag=0;
		}	
		if(cnt==0) flag=0;
		cnt=0;	
		for(int j=0;j<s1[i].size()&&flag;j++){
			if(s2[i][j]=='b') cnt++,pos2=j;
			else if(s2[i][j]!='a') flag=0;
			if(cnt>1) flag=0;
		}	
		if(cnt==0) flag=0;
		id1[i]=pos1,id2[i]=pos2;
	}
	//cerr<<flag<<endl;
	if(flag){
		while(q--){
			cin>>s>>t;
			m=s.size();
			ans=0;
			for(int i=0;i<m;i++){
				if(s[i]=='b') pos1=i;
				if(t[i]=='b') pos2=i;
			}
		//	cerr<<pos1<<" "<<pos2<<endl;
			for(int i=1;i<=n;i++){
		//		cerr<<id1[i]<<" "<<id2[i]<<endl;
				if(pos2-pos1==id2[i]-id1[i]&&pos1>=id1[i]) ans++;
			}
				
			cout<<ans<<endl;
		}
		return 0;
	}
/*	if(q==1){
		memset(nxt,0,sizeof(nxt));
		cin>>s>>t;
		m=s.size();
		s="0"+s,t="0"+t;
		for(int i=1,j=0;i<=m;i++){
			while(j&&s[j+1]!=s[i]) j=nxt1[j];
			if(s[j+1]==s[i]) j++;
			nxt1[i]=j;
		}
		for(int i=1,j=0;i<=m;i++){
			while(j&&t[j+1]!=t[i]) j=nxt2[j];
			if(t[j+1]==t[i]) j++;
			nxt2[i]=j;
		}
		for(int i=1;i<=n;i++){
			for(int j=0,k=m;j<s1[i].size();j++){
				while(k&&s[k+1]!=s1[i][j]) k=nxt[k];
				if(s[k+1]==s1[i][j]) k++;
				if(j==s1[i].size()-1&&(k-s1[i].size())&&) ans++;
			}
		}
	}
	while(q--){
		cin>>q;
	}*/
	while(q--){
		cin>>s>>t;
		ans=0;
		memset(cnt1,0,sizeof(cnt1));
		m=s.size();
		cnt1[0]=s[0]!=t[0]?1:0;
		for(int i=1;i<m;i++){
			if(s[i]!=t[i]) cnt1[i]++;
			cnt1[i]+=cnt1[i-1];
		}
		for(int i=1;i<=n;i++)
			for(int j=0,k=0;j<m;j++){
				k=0;
				while(k<s1[i].size()&&s[j+k]==s1[i][k]&&t[j+k]==s2[i][k]) k++;
				if(k>=s1[i].size()&&(j==0?1:cnt1[j-1]==0)&&(cnt1[m-1]-cnt1[j+k-1]==0)) ans++;
			//	cerr<<i<<" "<<j<<" "<<k<<endl;
		}
		cout<<ans<<"\n";	
	}
	return 0;
}

