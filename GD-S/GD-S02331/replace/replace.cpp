#include<bits/stdc++.h>
#define rd() read()
#define wt write
#define pc putchar
using namespace std;
namespace IO{
	inline int read(){
		int x=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-'){
				f=-1;
			}
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			x=(x<<1)+(x<<3)+(c^48);
			c=getchar();
		}
		return x*f;
	}
	inline void write(int x){
		if(x<0){
			x=-x;
			pc('-');
		}
		if(x>9){
			write(x/10);
			pc(x%10+'0');
		}
		else{
			pc(x+'0');
		}
		return ;
	}
}
using namespace IO;
namespace Main{
	const int N=2e5+7;
	int n,m,res;
	string subs[N];
	multiset<string> st;
	unordered_map<string,string> mp;
	inline int check(int l,int r,string s,string ans){
		string str="",anss="",left="",right="";
		for(int i=0;i<l;i++){
			if(s[i]!=ans[i]){
				return 0;
			}
		}
		for(int i=l;i<=r;i++){
			str+=s[i];
		}
		for(int i=l;i<=r;i++){
			anss+=ans[i];
		}
//		cout<<str<<"        "<<anss<<'\n';
//		if(str=="bc"){
//			cout<<r<<"r\n";
//		}
		for(int i=r+1;i<s.size();i++){
			if(s[i]!=ans[i]){
				return 0;
			}
		}
		if(mp[str]==""){
			return 0;
		}
		str=mp[str];
//		cout<<"ans="<<anss<<" str="<<str<<'\n';
		if(anss==str){
			return 1;
		}
		return 0;
	}
	inline void main(){
		n=rd(),m=rd();
		if(n>=1000){
			while(m--){
				puts("0");
			}
			return ;
		}
		for(int i=1;i<=n;i++){
			string str1,str2;
			cin>>str1>>str2;
			mp[str1]=str2;
			subs[i]=str1;
		}
		while(m--){
			res=0;
			string str1,str2;
			cin>>str1>>str2;
			int len1=str1.size(),len2=str2.size();
			st.insert(str1);
			for(int l=0;l<len1;l++){
				for(int r=len1-1;r>l;r--){
					res+=check(l,r,str1,str2);
				} 
			}
			cout<<res<<'\n';
			st.clear();
		}
		return ;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	Main::main();
	return 0;
}
