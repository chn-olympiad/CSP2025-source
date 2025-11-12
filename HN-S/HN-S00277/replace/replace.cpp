#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pb push_back
typedef pair<int,int>pii;
typedef vector<int>vint;
typedef vector<pii>vpii;

const int N=200010;
int n,q;
int sz[N];
string s1[N],s2[N];
string t1,t2;
vint mch[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		sz[i]=s1[i].size();
	}
	while(q--){
		cin>>t1>>t2;
		int s=t1.size(),ans=0;
		for(int i=1;i<=n;i++){
			bool fl=1;
			for(int j=0;j<s-sz[i]+1;j++){
				if(t1[j]!=s1[i][0]){
					for(int k=j;k<=j+sz[i]-1;k++){
						if(s1[i][k-j]!=t1[k]) {
							fl=0;break;
						}
						t1[k]=s2[i][k-j];
					}
					if(!fl) break;
				}
			}
			for(int j=0;j<s;j++)
				if(t1[j]!=t2[j]) fl=0;
			if(fl) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
Ren5Jie4Di4Ling5%
*/