#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10;
string s_fi[MAXN],s_se[MAXN];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s_fi[i]>>s_se[i];
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int ans=0;
		for(int i=1;i<=n;i++){		
			for(int now=0;now<s1.size();now++){
				if(s1[now]==s_fi[i][0]){
					int cnt=0;
					string tmp=s1;
					for(int cnt=0;cnt<s_fi[i].size();cnt++){
						if(tmp[now+cnt]!=s_fi[i][cnt])break; 
						tmp[now+cnt]=s_se[i][cnt];
					}
					if(tmp==s2){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

