#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define F std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,q,i,j,k,o;
pair<string,string> z[100005],p[100005];
int main(void){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	F;
	string r,s,t;
	cin>>n>>q;
	for(i=0,j=0;i<n;++i){
		cin>>s>>t;
		if(s==t)continue;
		z[j].first=s,z[j].second=t;
		p[j]=z[j];
		for(o=0;o<z[j].first.size();++o)
			if(z[j].first[o]!=z[j].second[o])break;
		for(k=z[j].first.size()-1;k>=o;--k)
			if(z[j].first[k]!=z[j].second[k])break;
		z[j].first=z[j].first.substr(o,k-o+1),z[j].second=z[j].second.substr(o,k-o+1);
		++j;
	}
	n=j,sort(z,z+n);
	while(q--){
		cin>>s>>t,r=s;
		if(s.size()!=t.size()){
			cout<<"0\n";
			continue;
		}
		for(i=0;i<s.size();++i)
			if(s[i]!=t[i])break;
		for(j=s.size()-1;j>=i;--j)
			if(s[j]!=t[j])break;
		s=s.substr(i,j-i+1),t=t.substr(i,j-i+1);
		pair<string,string> ppp={s,t};
		auto t1=lower_bound(z,z+n,ppp)-z;
		auto t2=upper_bound(z,z+n,ppp)-z;
		for(i=t1,j=0;i<t2;++i)j+=(r.find(p[t1].first)!=string::npos);
		cout<<j<<"\n";
	}
	return 0;
}
