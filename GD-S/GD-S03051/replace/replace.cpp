#include<bits/stdc++.h>
#define ll long long
#define hash_table pair<ll,ll>
using namespace std;
ll n,q,c,i,j,k,mo_size,r[5000005];
string s,t;
struct t_in{
	ll dp;
	hash_table hsh;
	t_in*s[680];
}t_in_empty,*g2;
struct t_out{
	t_out*s[680];
	vector<t_in>v;
	map<hash_table,ll>f;
}t_out_empty,*g1,*mo[5000005];
ll hsh1(string s){
	ll h=0;
	for(auto i:s)h=(h*998244353+i)%1000000007;
	return h;
}
ll hsh2(string s){
	ll h=0;
	for(auto i:s)h=(h*114514+i)%1919810;
	return h;
}
hash_table hsh(ll*l,ll*r){
	long long h1=0,h2=0;
	while(l<=r){
		h1=(h1*998244353+(*l))%1000000007;
		h2=(h2*114514+(*l))%1919810;
		l++;
	}
	return make_pair(h1,h2);
}
ll hash_pair(char a,char b){return (a-'a')*26+b-'a';}
hash_table h,ih;
map<hash_table,vector<t_out> >mp;
map<hash_table,bool>bl;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>s>>t;
		for(j=0;j<s.size()&&s[j]==t[j];j++);
		for(k=s.size()-1;k>=j&&s[k]==t[k];k--);
		h=make_pair(hsh1(s.substr(j,k-j+1)),hsh2(s.substr(j,k-j+1)));
		for(j=0;j<s.size();j++)r[j]=hash_pair(s[j],t[j]);
		if(mp[h].empty())mp[h].push_back(t_out_empty);
		g1=&mp[h][0];
		for(j--;~j;j--){
			if((*g1).s[r[j]]==nullptr){
				mp[h].push_back(t_out_empty);
				(*g1).s[r[j]]=&mp[h].back();
			}
			g1=(*g1).s[r[j]];
		}
		if((*g1).v.empty())(*g1).v.push_back(t_in_empty);
		g2=&((*g1).v[0]);
		for(k++;k<s.size();k++){
			if(!(*g2).s[r[k]]){
				(*g1).v.push_back(t_in_empty);
				(*g1).v.back().hsh.first=((*g2).hsh.first*998244353+s[k])%1000000007;
				(*g1).v.back().hsh.second=((*g2).hsh.second*114514+s[k])%1919810;
				(*g2).s[r[k]]=&(*g1).v.back();
			}
			g2=(*g2).s[r[k]];
		}
		(*g2).dp++;
		ih=hsh(r,r+j-1);
		if(!bl[ih]){
			mo[mo_size++]=g1;
			bl[ih]=1;
		}
	}
	for(i=0;i<mo_size;i++){
		for(j=0;j<(*mo[i]).v.size();j++){
			(*mo[i]).f[(*mo[i]).v[j].hsh]=(*mo[i]).v[j].dp;
			for(k=0;k<676;k++)(*(*mo[i]).v[j].s[k]).dp+=(*mo[i]).v[j].dp;
		}
	}
	while(q--){
		cin>>s>>t;
		for(j=0;j<s.size()&&s[j]==t[j];j++);
		for(k=s.size()-1;k>=j&&s[k]==t[k];k--);
		h=make_pair(hsh1(s.substr(j,k-j+1)),hsh2(s.substr(j,k-j+1)));
		for(j=0;j<s.size();j++)r[j]=hash_pair(s[j],t[j]);
		ih=hsh(r+k+1,r+s.size()-1);
		c=0;
		g1=&mp[h][0];
		for(j--;~j;j--){
			if((*g1).s[r[j]]==nullptr)break;
			c+=(*g1).f[ih];
			g1=(*g1).s[r[j]];
		}
		cout<<c;
	}
	return 0;
}
//字典树套字典树,O((n+q)logn+L1+L2)
//调了1h，终于不CE了
//UB，这句mp[h].push_back(t_out_empty);RE了
//还剩0.5h
//还剩3min 
//give up
