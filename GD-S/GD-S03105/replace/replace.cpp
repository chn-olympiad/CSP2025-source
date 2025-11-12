#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
string str;
string str1[1005],str2[1005];
int ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>str1[i]>>str2[i];
	while(q--){
		cin>>str;
		for(int i=1;i<=n;i++){
			for(int len=1;len<str1[i].size() and len<str.size();i++){
				for(int j=0;j+len-1<n;j++){
					string a=str.substr(j,len);
					int x=0;
					while(str1[i].find(a,x)>=0 and str1[i].find(a,x)<int(str1[i].size())){
						ans++;
						x=str1[i].find(a,x)+len;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

