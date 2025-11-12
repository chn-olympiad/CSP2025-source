#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int N=2e5+5,M=5e6+5,p=131;
int n,q,ans,len,l[N],r[N];
unsigned long long h1[N],h2[N],H[M],POW[M]={1};
string s1,s2;
vector<pair<pair<int,unsigned long long>,pair<int,unsigned long long> > > t[N];
map<pair<unsigned long long,unsigned long long>,int> mp;
unsigned long long calc(int l,int r){
	if(l>r)return 0;
	return H[r]-H[l-1]*POW[r-l+1];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int l=0,r=s1.size()-1;
		unsigned long long hl=0,hr=0,h1=0,h2=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				l=j;
				break;
			}else hl=hl*p+s1[j];
		}
		for(int j=s1.size()-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				r=j;
				for(int k=j+1;k<s1.size();k++)hr=hr*p+s1[k];
				break;
			}
		}
		for(int i=l;i<=r;i++)h1=h1*p+s1[i];
		for(int i=l;i<=r;i++)h2=h2*p+s2[i];
		if(!mp[make_pair(h1,h2)])mp[make_pair(h1,h2)]=++len;
		t[mp[make_pair(h1,h2)]].push_back(make_pair(make_pair(l,hl),make_pair(s1.size()-1-r,hr)));
	}
	while(q--){
		cin>>s1>>s2;ans=0;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		H[0]=s1[0];
		for(int i=1;i<s1.size();i++)H[i]=H[i-1]*p+s1[i];
		int l=0,r=s1.size()-1;
		unsigned long long h1=0,h2=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				l=j-1;
				break;
			}
		}
		for(int j=s1.size()-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				r=j+1;
				break;
			}
		}
		for(int i=l+1;i<=r-1;i++)h1=h1*p+s1[i];
		for(int i=l+1;i<=r-1;i++)h2=h2*p+s2[i];
		int xb=mp[make_pair(h1,h2)];
		for(int i=0;i<t[xb].size();i++){
			int len1=t[xb][i].first.first,len2=t[xb][i].second.first;
			unsigned long long S1=t[xb][i].first.second,S2=t[xb][i].second.second;
			if(l-len1+1>=0&&r+len2-1<s1.size())ans+=(calc(l-len1+1,l)==S1&&calc(r,r+len2-1)==S2);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
