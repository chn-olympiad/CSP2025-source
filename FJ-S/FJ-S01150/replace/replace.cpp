#include<bits/stdc++.h>
using namespace std;
const int N=6e6+5,P=131;
int n,q;
string s,t;
int son[N][26],dui[N];
int tot,cnt,rt[N],bb[N];
int sm[N],fail[N];
unordered_map<long long,int>mp;
void bfs(){
	int r=0,l=0;
	for(int i=1;i<=tot;++i){
		for(int j=0;j<26;++j)
		if(son[rt[i]][j])dui[++r]=son[rt[i]][j],fail[son[rt[i]][j]]=rt[i];
		else son[rt[i]][j]=rt[i];
	}
	while(l<r){
		int x=dui[++l];
		for(int i=0;i<26;++i){
			if(!son[x][i])son[x][i]=son[fail[x]][i];
			else{
				fail[son[x][i]]=son[fail[x]][i];
				dui[++r]=son[x][i];
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s>>t;
		int m=s.size(),l,r;
		for(l=0;l<m;++l)
		if(s[l]!=t[l])break;
		for(r=m-1;r>=0;--r)
		if(s[r]!=t[r])break;
		if(l>r)continue;
		long long sum=0;//cout<<l<<" "<<r<<"??\n";
		for(int i=l;i<=r;++i)sum=sum*P+s[i];
		sum=sum*P+'#'; 
		for(int i=l;i<=r;++i)sum=sum*P+t[i];//cout<<sum<<"\n";
		if(!mp[sum])mp[sum]=++tot;
		if(!rt[mp[sum]])rt[mp[sum]]=++cnt;
		int rot=rt[mp[sum]];
		for(int i=0;i<m;++i){
			if(!son[rot][s[i]-'a'])son[rot][s[i]-'a']=++cnt;
			rot=son[rot][s[i]-'a'];
//			cout<<rot<<' ';
		}//cout<<'\n';
//		cout<<rot<<' '<<mp[sum]<<"??\n";
		++sm[rot];
	}
	bfs();//cout<<fail[5]<<"??\n";
	while(q--){
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<0<<'\n';
			continue;
		}
		int l,r,m=s.size();
		for(l=0;l<m;++l)
		if(s[l]!=t[l])break;
		for(r=s.size()-1;r>=0;--r)
		if(s[r]!=t[r])break;
		long long sum=0;
		for(int i=l;i<=r;++i)sum=sum*P+s[i];
		sum=sum*P+'#';
//		cout<<l<<' '<<r<<"??\n";
		for(int i=l;i<=r;++i)sum=sum*P+t[i];
		if(!mp[sum]){//cout<<sum<<"?\n";
			cout<<0<<'\n';
			continue;
		}
		int rot=rt[mp[sum]],anss=0;
		r=0;
		for(int i=0;i<m;++i){
			if(!son[rot][s[i]-'a'])son[rot][s[i]-'a']=++cnt;
			rot=son[rot][s[i]-'a'];
			int x=rot;
			while(x){
				if(!bb[x])dui[++r]=x,bb[x]=1;
				else break;
				x=fail[x];
			}
//			anss+=sm[rot];
		}
		for(int i=1;i<=r;++i)
		bb[dui[i]]=0,anss+=sm[dui[i]];
		cout<<anss<<'\n';
	}
}
