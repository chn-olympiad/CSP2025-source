#include<bits/stdc++.h>
using namespace std;
map<pair<string,string>,pair<int,int> >mp;
int l[200010],r[200010],n,q;
int trie[6000010][30],num_node;
vector<int>p[6000010];
pair<int,int>solve(string a,string b){
	int l=0,r=-1,len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]!=b[i]){
			l=i;break;
		}
	}
	for(int i=len-1;i>=0;i--){
		if(a[i]!=b[i]){
			r=i;break;
		}
	}string k1="",k2="";
	for(int i=l;i<=r;i++){
		k1+=a[i];
		k2+=b[i];
	}//cout<<k1<<" "<<k2<<"\n";
	if(!mp.count(make_pair(k1,k2))){
		mp[make_pair(k1,k2)]=make_pair(num_node+1,num_node+2);
		num_node+=2;
	}int w1=mp[make_pair(k1,k2)].first;
	for(int i=l-1;i>=0;i--){
		//cout<<w1<<" ";
		if(!trie[w1][a[i]-'a'+1])
			trie[w1][a[i]-'a'+1]=++num_node;
		w1=trie[w1][a[i]-'a'+1];
	}//cout<<w1<<"\n";
	int w2=mp[make_pair(k1,k2)].second;
	for(int i=r+1;i<len;i++){
		//cout<<w2<<" ";
		if(!trie[w2][a[i]-'a'+1])
			trie[w2][a[i]-'a'+1]=++num_node;
		w2=trie[w2][a[i]-'a'+1];
	}//cout<<w2<<"\n";
	return make_pair(w1,w2);
}int ans[200010];
void query(string a,string b,int k){
	int l=0,r=-1,len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]!=b[i]){
			l=i;break;
		}
	}
	for(int i=len-1;i>=0;i--){
		if(a[i]!=b[i]){
			r=i;break;
		}
	}string k1="",k2="";
	for(int i=l;i<=r;i++){
		k1+=a[i];
		k2+=b[i];
	}//cout<<k1<<" "<<k2<<"\n";
	if(!mp.count(make_pair(k1,k2))){
		return;
	}int w1=mp[make_pair(k1,k2)].first,f1=true;
	for(int i=l-1;i>=0;i--){
		//cout<<w1<<" ";
		p[w1].push_back(k);
		if(!trie[w1][a[i]-'a'+1]){
			f1=false;break;
		}w1=trie[w1][a[i]-'a'+1];
	}//cout<<w1<<"\n";
	if(f1)p[w1].push_back(k);
	int w2=mp[make_pair(k1,k2)].second,f2=true;
	for(int i=r+1;i<len;i++){
//		cout<<w2<<" ";
		p[w2].push_back(k);
		if(!trie[w2][a[i]-'a'+1]){
			f2=false;break;
		}
		if(f2)w2=trie[w2][a[i]-'a'+1];
	}//cout<<w2<<"\n";
	if(f2)p[w2].push_back(k);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1==s2)continue;
		//cout<<i<<":\n";
		pair<int,int>x=solve(s1,s2);
		l[i]=x.first;r[i]=x.second;
	}for(int k=1;k<=q;k++){
		string t1,t2;
		cin>>t1>>t2;
//		if(k!=1070)
//			continue;
//		cout<<q<<" ";
		if(t1.size()!=t2.size()){
			continue;
		}else query(t1,t2,k);
	}
	for(int i=1;i<=n;i++){
		if(l[i]==0)continue;
		for(int x=0,y=0;x<(int)p[l[i]].size()&&y<(int)p[r[i]].size();){
			if(p[l[i]][x]<p[r[i]][y])x++;
			else if(p[l[i]][x]>p[r[i]][y])y++;
			else{
				ans[p[l[i]][x]]++;
				x++;y++;
			}
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	return 0;
}

