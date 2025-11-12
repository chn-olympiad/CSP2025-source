#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[500005],s[500005];
string to_str(int a){
	string ret="";
	while(a){
		ret=to_string(a%2)+ret;
		a/=2;
	}while(ret.size()<20){
		ret="0"+ret;
	}return ret;
}
struct trie{
	int to[10000005][2],len,val[10000005];
	bool have[10000005];
	void insert(int a,int b){
		int p=0;
		string s=to_str(a);
		for(int i=0;i<(int)s.size();i++){
			if(!to[p][s[i]-'0']){
				to[p][s[i]-'0']=++len;
			}p=to[p][s[i]-'0'];
		}val[p]=max(val[p],b);
		have[p]=1;
	}int find(int a){
		int p=0;
		string s=to_str(a);
		for(int i=0;i<(int)s.size();i++){
			if(!to[p][s[i]-'0']){
				return -1;
			}
			p=to[p][s[i]-'0'];
		}
		if(have[p])return val[p];
		else return -1;
	}
}T;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}T.insert(0,0);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		f[i]=max(T.find(k^s[i])+1,f[i]);
		T.insert(s[i],f[i]);
	}printf("%d",f[n]);
}