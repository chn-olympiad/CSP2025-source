#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN=2e5+7,base=131,MAXL=5e6+7;
ull pown[MAXL]={1};
ull ts1[MAXN],ts2[MAXN];
int len[MAXN];
void make_hs(ull &hs,string s){
	for(int i=0;i<s.size();i++){
		hs=hs*base+s[i]-'0';
	}
}

ull hs[MAXL],qs2;
int n,q;
ull geth(int l,int r){
	return hs[r]-hs[l-1]*pown[r-l+1];
}
unordered_map<string,vector<int> > pp;
int main(){
	string s1,s2;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int i=1;i<MAXL;i++)pown[i]=pown[i-1]*base;
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ull hs1,hs2;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		make_hs(ts1[i],s1);
		make_hs(ts2[i],s2);
		//cout<<"from:"<<s1.substr(0,3)<<'\n';
		pp[s1.substr(0,1)].push_back(i);
		len[i]=s1.size();
	}
	
	while(q--){
		qs2=0;
		int ans=0;
		cin>>s1>>s2;
		s1=' '+s1;;
		for(int i=1;i<s1.size();i++){
			hs[i]=hs[i-1]*base+s1[i]-'0';
		}
		make_hs(qs2,s2);
		for(int i=1;i<s1.size();i++){
				string gh=s1.substr(i,1);
				for(auto j:pp[gh]){
					if(i+len[j]-1<s1.size()&&geth(i,i+len[j]-1)==ts1[j]){
						//cout<<"match"<<' '<<s1.substr(i,len[j])<<'\n';
						//cout<<" with "<<j<<'\n';
						//cout<<"yes1\n";
						ull tmp;
						tmp=geth(i+len[j],s1.size()-1);
						tmp+=ts2[j]*pown[s1.size()-i-len[j]];
						tmp+=geth(1,i-1)*pown[s1.size()-i];
						if(tmp==qs2){
							//cout<<"yes2\n";
							ans++;
						}
					}
				}
		}
		cout<<ans<<'\n';
	}
}
