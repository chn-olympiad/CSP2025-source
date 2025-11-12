#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+5; 

int n,m,p[N],ans;
string s1[N],s2[N];
vector<int> e;

int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void kmp(string s,string t){
	p[1]=0;e.clear();
	int ls=s.size()-1,ts=t.size()-1;
	for(int i=2,j=0;i<=ts;++i){
		while(j&&t[j+1]!=t[i])j=p[j];
		j+=(t[j+1]==t[i]),p[i]=j;
	}
	for(int i=1,j=0;i<=ls;++i){
		while(j&&t[j+1]!=s[i])j=p[j];
		j+=(t[j+1]==s[i]);
		if(j==ts)e.push_back(i),j=p[j];
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	n=read(),m=read(); 
	string t1,t2;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		s1[i]=' '+s1[i],s2[i]=' '+s2[i];
	}
	while(m--){
		ans=0;
		cin>>t1>>t2;t1=' '+t1,t2=' '+t2;
		for(int i=1;i<=n;++i){
			kmp(t1,s1[i]);
			for(int x:e){
				int len=s2[i].size()-1;
				string t=t1;
				for(int j=1;j<=len;++j)t[x-len+j]=s2[i][j];
				if(t==t2)++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

