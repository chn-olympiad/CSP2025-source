#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int Base=13331;
int n,qq;
string s1[N],s2[N],t1[N],t2[N];
typedef unsigned long long ULL;
ULL h[N],ha1[N],ha2[N];
ULL ha3[N],ha4[N];
int x[N],y[N];
int cnt;
map<ULL,int> mp;
vector<int> g[N];
ULL ha(string s){
	ULL res=0;
	for(int i=0;i<s.size();i++){
		res=res*Base+(s[i]-'a'+1);
	}
	return res;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>qq;
	string s3;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		if(s1[i]==s2[i])continue ;
		int p=0,q=s1[i].size()-1;
		while(s1[i][p]==s2[i][p])p++;
		while(s1[i][q]==s2[i][q])q--;
		s3=s1[i].substr(p,q-p+1)+s2[i].substr(p,q-p+1); 
		ULL hsh=ha(s3);
		if(!mp.count(hsh)){
			mp[hsh]=++cnt;
		}
		g[mp[hsh]].push_back(i);
		x[i]=p,y[i]=s1[i].size()-q-1;
		s3=s1[i].substr(0,p);
		for(int j=0;j<p;j++){
			s3[j]=s1[i][p-j-1];
		}
		if(p)ha1[i]=ha(s3);
		if(q+1<s1[i].size())ha2[i]=ha(s1[i].substr(q+1,y[i]));
		//cout<<s3<<endl; 
	}
	for(int i=1;i<=qq;i++){
		cin>>t1[i]>>t2[i];
	}
	//puts("***");
	for(int i=1;i<=qq;i++){
		if(t1[i].size()!=t2[i].size()){
			cout<<0<<endl;
			continue ;
		}
		int p=0,q=t1[i].size(),len=t1[i].size();
		while(t1[i][p]==t2[i][p])p++;
		while(t1[i][q]==t2[i][q])q--;
		s3=t1[i].substr(p,q-p+1)+t2[i].substr(p,q-p+1); 
		ULL hsh=ha(s3);
		int res=0;
		if(mp.count(hsh)){
			int k=mp[hsh],xx=p,yy=len-q-1;
			ha3[p]=ha4[q]=0;
			for(int j=p-1;j>=0;j--){
				ha3[j]=ha3[j+1]*Base+(t1[i][j]-'a'+1);
			}
			for(int j=q+1;j<len;j++){
				ha4[j]=ha4[j-1]*Base+(t1[i][j]-'a'+1);
			}
			//cout<<xx<<" "<<yy<<' '<<hsh<<endl;
			for(int j=0;j<g[k].size();j++){
				int u=g[k][j];
				if(x[u]<=xx&&y[u]<=yy&&ha3[p-x[u]]==ha1[u]&&ha4[q+y[u]]==ha2[u]){
					res++;
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
