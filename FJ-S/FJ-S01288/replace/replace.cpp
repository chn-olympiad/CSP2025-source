#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,q,ans;
string s1[200005],s2[200005],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		ans=0;
		for(int i=1;i<=n;i++){
			int l1=t1.size(),l2=s1[i].size();
			for(int j=0;j<l1-l2+1;j++){
				string y=t1.substr(j,l2);
				if(y==s1[i]){
					string xx=t1;
					for(int k=0;k<l2;k++){
						xx[j+k]=s2[i][k];
					}
					if(xx==t2) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
