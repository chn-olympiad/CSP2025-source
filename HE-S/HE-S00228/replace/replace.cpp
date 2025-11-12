#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T&x){
	x=0;char c;int sgin=1;
	do{
		c=getchar();
		if(c=='-')sgin=-1;
	}while(!isdigit(c));
	do{
		x=(x<<3)+(x<<1)+(c&15);
		c=getchar();
	}while(isdigit(c));
	x*=sgin;
}
map<string,map<string,bool> > vis;
map<string,bool> vis1;
map<char,int> vis2;
int n,q,ans;
string t1,t2;
void dfs(string a,string b,int l,int r,bool f){
//	cout<<a<<" "<<b<<endl;
	if(vis[a][b]){
		bool flag=true;
		for(int i=0;i<t1.size();i++){
			if(i<l||i>=r){
				if(t1[i]!=t2[i]){
					flag=false;
					break;
				}
			}
		}
		if(flag)ans++;
	}
	if(r<t1.size())dfs(a+t1[r],b+t2[r],l,r+1,true); 
	string fw1="",fw2="";
	fw1+=t1[r];
	fw2+=t2[r];
	if(r<t1.size()&&f&&r!=0)dfs(fw1,fw2,r,r+1,false);
}
void dfss(string a,string b,int l,int r){
	if(vis[a][b]&&!vis1[a])ans++,vis1[a]=true;
	if(l>=0)dfss(t1[l]+a,t2[l]+b,l-1,r);
	if(r<t1.size())dfss(a+t1[r],b+t2[r],l,r+1);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);
	read(q);
	bool flag=true;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(flag){
			int cnt=0;
			vis2.clear();
			for(int i=0;i<s1.size();i++){
				if(vis2[s1[i]]==false){
					vis2[s1[i]]=true;
					cnt++;
				}
				if(cnt>2)break;
			}
			if(cnt!=2){
				flag=false;
			}
			cnt=0;
			vis2.clear();
			for(int i=0;i<s2.size();i++){
				if(vis2[s2[i]]==false){
					vis2[s2[i]]=true;
					cnt++;
				}
				if(cnt>2)break;
			}
			if(cnt!=2){
				flag=false;
			}
		}
		vis[s1][s2]=true;
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int cnt1=0,cnt2=0,biao;
		for(int i=0;i<t1.size();i++){
			vis2[t1[i]]++;
			vis2[t1[i]]++;
		}
		bool flagh=true;
		map<char,int>::iterator it;
		for(it=vis2.begin();it!=vis2.end();it++){
			if(it->second==2)cnt1++;
			cnt2++;
		}
		for(int i=1;i<t1.size()-1;i++){
			if(t1[i]!=t1[i-1]&&t1[i]!=t1[i-1]){
				biao=i;
				break;
			}
		}
		if(cnt1!=2||cnt2!=2||!flag||cnt1!=1||cnt2!=2){
			ans=0;
			dfs("","",0,0,true);
			cout<<ans<<'\n';
		}
		else{
			vis1.clear();
			ans=0;
			dfss("","",biao,biao);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
