#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
typedef long long ll;
int n,q;
const int base = 31;
const int MOD = 1e9+7;
const int N = 2e5+5;
string s1[N],s2[N],t1,t2;
int len[N];
int cnt = 0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		len[i] = s1[i].size();
	}
	while(q--){
		cin>>t1>>t2;
		cnt = 0;
		int le1 = t1.size(),le2 = t2.size();
		if(le1 != le2){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;++i){
			for(int j=0;j<le1;++j){
				int k;
				for(k=0;k<len[i];++k){
					if(t1[j+k] != s1[i][k])break;
				}
				if(k != len[i])continue;
				for(k=0;k<len[i];++k){
					t1[j+k] = s2[i][k];
				}
				if(t1 == t2)++cnt;
				for(k=0;k<len[i];++k){
					t1[j+k] = s1[i][k];
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
