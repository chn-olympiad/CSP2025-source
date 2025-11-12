#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][3],t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;++i){
		int cnt=0;
		cin>>t1>>t2;
		int len=t1.size();
		int sum=0;
		for(int j=0;j<len;++j){
			if(t1[j]!=t2[j]) ++sum;
		}
		for(int j=1;j<=n;++j){
			for(int k=0;k<=len-(int)s[j][1].size();++k){
				bool flag=true;
				int num=0;
				for(int l=0;l<(int)s[j][1].size();++l){
					//cout<<"_____"<<k+l<<' '<<l<<'\n';
					if(t1[k+l]!=s[j][1][l] || t2[k+l]!=s[j][2][l]){
						flag=false;
						break;
					}
					if(t1[k+l]!=t2[k+l]) ++num;
				}
				if(flag && num==sum) ++cnt;
			}
		}
		cout<<cnt<<'\n';
		/*for(int j=0;j<len;++j){
			
		}*/
	}
	return 0;
}
