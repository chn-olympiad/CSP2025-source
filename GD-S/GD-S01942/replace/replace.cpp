#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=5e6+10,inf=1e9+10;

std::vector<int>a[N];
int b[M];
int main(){
	freopen("replace.in","r",stdin);
//	freopen("replace4.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		string s1,s2;
		cin>>s1>>s2;
		int n=s1.size();
		a[i].resize(n);
		for(int j=0;j<n;++j)
			a[i][j]=(s1[j]-'a')*26+s2[j]-'a';
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int m=t1.size(),l=-1,r=-1;
		for(int i=0;i<m;++i){
			b[i]=(t1[i]-'a')*26+t2[i]-'a';
			if(t1[i]!=t2[i]){
				if(l==-1)l=i;
				r=i;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			int t=a[i].size();
			for(int j=max(0,r-t+1);j<=min(l,m-t);++j){
				bool flag=1;
				for(int k=0;k<t;++k)
					if(a[i][k]!=b[j+k]){
						flag=0;break;
					}
				if(flag){
					++cnt;break;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
