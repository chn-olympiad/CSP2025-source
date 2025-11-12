#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
int t,n;
struct str{
	int aa,ab,ac;
};
map<int,vector<pair<int,int>>>m;
int bmcnt[4];
int yaq=0;
long long ans=0;
bool xgood[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		yaq=n/2;
		ans=0;
		m.clear();
		memset(bmcnt,0,sizeof(bmcnt));
		memset(xgood,0,sizeof(xgood));
		str b1;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&b1.aa,&b1.ab,&b1.ac);
			m[b1.aa].push_back(make_pair(1,i));
			m[b1.ab].push_back(make_pair(2,i));
			m[b1.ac].push_back(make_pair(3,i));
		}
		auto it=m.end();
		it--;
		for(;;it--){
			for(auto qit=it->second.begin();qit!=it->second.end();qit++){
				if(bmcnt[qit->first]+1<=yaq&&xgood[qit->second]==false){
					bmcnt[qit->first]++;
					xgood[qit->second]=true;
					ans=ans+it->first;
				}
			}
			if(it==m.begin()){
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*if(it==m.bgein()){
				break;
			}*/
