#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--){
		string a,b;
		int ans=0;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		int l1=a.size(),l2;
		for(int i=1;i<=n;i++){
			l2=s1[i].size();
			for(int j=0;j<l1;j++){
				bool f=0;
				for(int k=0;k<l2;k++)
					if(a[j+k]!=s1[i][k]||b[j+k]!=s2[i][k]){
						f=1;
						break;
					}
				if(f==0){
					for(int k=0;k<j;k++)
						if(a[k]!=b[k]){
							f=1;
							break;
						}
					for(int k=j+l2;k<l1;k++)
						if(a[k]!=b[k]){
							f=1;
							break;
						}
					if(f==0){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
