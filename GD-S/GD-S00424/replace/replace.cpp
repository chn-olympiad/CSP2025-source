#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
map<string,string>m;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		m[s1]=s2;
	}
	for(int i=0;i<q;i++){
		string x,y;
		cin>>x>>y;
		int n=x.size();
		int qz=0,hz=n-1,ans=0;
		while(x[qz]==y[qz])qz++;
		while(x[hz]==y[hz])hz--;
		for(int i=0;i<=qz;i++){
			for(int j=hz;j<n;j++){
				if(i==j)break;
				string s1=x.substr(i,j-i+1),s2=y.substr(i,j-i+1);
				if(m[s1]==s2)ans++; 
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
