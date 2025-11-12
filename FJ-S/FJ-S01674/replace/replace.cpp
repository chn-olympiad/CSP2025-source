#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int n,q,ans;
unsigned seed;
string x,y;
unordered_map<string,string> mp;
set<int> st;
inline string get(string x,int l,int r){
	return x.substr(l,r-l);
}
inline unsigned xorshift32(){
	seed^=seed<<13;seed^=seed>>17;seed^=seed<<5;
	return seed;
}
inline void find(int l){
	for(auto i:st){
		int r=l+i-1;
		if(r>=x.length())break;
		string sub=get(x,l,r+1);
		if(mp.count(sub)){
			string now=""; 
			for(int i=0;i<l;i++)now+=x[i];
			now+=mp[sub];
			for(int i=r+1;i<x.length();i++)now+=x[i];
			if(now==y)ans++;
		}
	}
}
inline unsigned myabs(unsigned a){
	return (a>0?a:-a);
} 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>q;seed=lowbit(n^q)+42;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		mp[x]=y;
		st.insert(x.length());
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=0;
		if(x.length()<=200){
			for(int l=0;l<x.length();l++)find(l);
		}
		else{
			for(int i=1;i<=20;i++)find(myabs(xorshift32())%x.length());
		}
		cout<<ans<<'\n';
	}
}
