//GZ-S00322 北京师范大学贵阳附属中学 王明轩 
#include <bits/stdc++.h>
#include <string>
using namespace std;
int n,q;
string s1[200010],s2[200010];
int ans[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		for(int j=1;j<=n;j++){
			for(int k=0;k<t1.size()-s1[j].size();k++){
				string temp=t1.substr(k,s1[j].size());
				if(temp==s1[j]){
					temp=t1.substr(0,k)+s1[j]+t1.substr(k+s1[j].size());
					if(temp==t2){
						ans[i]++;
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
