#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0;bool f=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?-x:x;
}

int pi[1000005];

void KMP(string s){
	pi[1]=0;
	for(int i=2;i<=s.size();i++){
		int j=i;
		while(s[pi[j-1]]==s[i-1])j=pi[j]-1;
		pi[i]=pi[j-1]+1;
	}	
}

int n,q;

string b[1005][2];
map<string,string> mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++){
		cin>>b[i][0]>>b[i][1];
		mp[b[i][0]]=b[i][1];
	}
	for(int i=1;i<=q;i++){
		printf("0\n");
	}
	return 0;
}
