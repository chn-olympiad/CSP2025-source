#include<bits/stdc++.h>
#define N 200005
using namespace std;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
int n,q;
string s[N][2],t[N][2];
long long ans;
unordered_map< int,vector<int> >cnt1;
unordered_map< int,vector<int> >cnt2;
int main(){
//	freopen("replace4.in","r",stdin);
//	freopen("replace4.out","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;++i){
		char c;
		while(c=getchar()){
			if(c==' ')break;
			s[i][1]+=c;
		}
		while(c=getchar()){
			if(c=='\n')break;
			s[i][2]+=c;
		}
		int pos1=0,pos2=0;
		int s_size=s[i][1].size();
		for(int j=0;j<s_size;j++){
			if(s[i][1][j]=='b')pos1=j;
			if(s[i][2][j]=='b')pos2=j;
		}
		if(pos1==pos2)continue;
		cnt1[pos2-pos1].push_back(pos1);
		cnt2[pos2-pos1].push_back(s_size-pos1);
	}
	for(int i=1;i<=q;++i){
		ans=0;
		char c;
		while(c=getchar()){
			if(c==' ')break;
			t[i][1]+=c;
		}
		while(c=getchar()){
			if(c=='\n')break;
			t[i][2]+=c;
		}
		int pos1=0,pos2=0;
		int t_size=t[i][1].size();
		for(int j=0;j<t_size;j++){
			if(t[i][1][j]=='b')pos1=j;
			if(t[i][2][j]=='b')pos2=j;
		}
		for(int j=0;j<cnt1[pos2-pos1].size();j++){
			if(pos1>=cnt1[pos2-pos1][j]&&t_size-pos1>=cnt2[pos2-pos1][j])ans++;
		}
		cout<<ans<<"\n";
	}
}

