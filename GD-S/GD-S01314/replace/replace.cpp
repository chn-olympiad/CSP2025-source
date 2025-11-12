#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int N=2e5+5;
const unsigned long long nul=0xffffffffffffffff;
int n,q;
string s[N][2],t1,t2;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;++i){
		int ans=0;
		cin>>t1>>t2;
		int l1=t1.size(),l2=t2.size();
		if(l1!=l2){
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;++j){
			auto pos1=t1.find(s[j][0]);
			if(pos1!=nul){
				bool f=true;
				for(int k=0;k<pos1;++k){
					if(t1[k]!=t2[k]){
						f=false;
						goto NOT;
					}
				}
				for(int k=0;k<s[j][0].size();++k){
					if(s[j][1][k]!=t2[k+pos1]){
						f=false;
						goto NOT;
					}
				}
				for(int k=pos1+s[j][0].size();k<l2;++k){
					if(t1[k]!=t2[k]){
						f=false;
						goto NOT;
					}
				}
				NOT:
				if(f) ++ans;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

