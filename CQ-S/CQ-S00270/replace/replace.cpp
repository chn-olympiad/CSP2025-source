#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e7+5; 
string s1,s2;
int n,q,oka,okb;
struct l{
	int la,lb;
};
bool cmp(l a,l b){
	return a.la<b.la;
}
vector<l>num[MAXN];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int len=s1.size();
		for(int j=0;j<len;j++){
			if(s1[j]=='b'){
				oka=j;
			}
			if(s2[j]=='b'){
				okb=j;
			}
		}
		num[oka-okb+5000000].push_back({oka,len-oka-1});
	}
	for(int i=0;i<=10000000;i++){
		sort(num[i].begin(),num[i].end(),cmp);
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		int len=s1.size();
		for(int j=0;j<len;j++){
			if(s1[j]=='b'){
				oka=j;
			}
			if(s2[j]=='b'){
				okb=j;
			}
		}
		int ans=0,zb=oka-okb+5000000;
		for(int j=0;j<num[zb].size();j++){
			if(num[zb][j].la>oka){
				break;
			}
			ans+=(num[zb][j].lb<=len-oka-1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
