#include<bits/stdc++.h>
using namespace std;
int n,T,sc,c,l,r,ans;string s1[200010],s2[200010],qs1,qs2;bool p;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(T--){
		cin>>qs1>>qs2;ans=0;
		if(qs1.size()!=qs2.size()){
			cout<<0<<"\n";continue;
		}
		for(int i=0;i<qs1.size();i++){
			if(qs1[i]!=qs2[i]){l=i;break;}
		}
		for(int i=qs1.size()-1;i>=0;i--){
			if(qs1[i]!=qs2[i]){r=i;break;}
		}
		for(int i=1;i<=n;i++){
			c=0;p=false;
			for(int j=0;j<qs1.size();j++){
				if(qs1[j]==s1[i][c]&&qs2[j]==s2[i][c]){
					c++;
					if(c==s1[i].size()&&j>=r){p=true;break;cout<<j<<" "<<c<<"|";}
				}
				else if(qs1[j]!=qs2[j])break;
				else if(j>=l)break;
				else c=0;
			}
			if(p)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

