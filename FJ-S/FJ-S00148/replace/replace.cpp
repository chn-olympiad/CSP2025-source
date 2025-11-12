#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
pair<string,string>ns[200005];
bool cmp(pair<string,string>u,pair<string,string>v){
	return u.first.size()<v.first.size();
}int s=0;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>ns[i].first>>ns[i].second;
	}sort(ns+1,ns+1+n,cmp);
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		s=0;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		for(int j=1;j<=n&&ns[j].first.size()<=t1.size();j++){
			signed l1=t1.find(ns[j].first),l2=t2.find(ns[j].second);
			if(l1==-1||l2==-1)continue;
			if(l1!=l2)continue;
			if(l1>0&&l2>0&&t1.substr(0,l1-1)!=t2.substr(0,l2-1))continue;
			if(t1.substr(l1+ns[j].first.size(),t1.size()-l1-ns[j].first.size()+1)!=t2.substr(l2+ns[j].second.size(),t2.size()-l2-ns[j].second.size()+1)){
				continue;
			}s++;
		}printf("%lld\n",s);
	}
	
	return 0;
}
