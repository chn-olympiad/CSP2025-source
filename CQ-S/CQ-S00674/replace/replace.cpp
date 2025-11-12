#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005],t1[200005],t2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		if(t1[i].size()==t2[i].size()){
			for(int j=1;j<=n;j++){
				int y=0;
				string h=t1[i];
				for(int l=0;l<t1[i].size();l++){
					if(t1[i][l]==s1[j][y]&&t2[i][l]==s2[j][y])y++;
					else y=0;
					//cout<<y;
					if(y==s1[j].size()){
						for(int p=l-s1[j].size()+1;p<=l;p++){
							t1[i][p]=s2[j][p-l+s1[j].size()-1];
						}
						break;
					}
					
				}
				//cout<<t1[i];
				if(t1[i]==t2[i])ans++;
				t1[i]=h;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

