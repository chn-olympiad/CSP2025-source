#include<bits/stdc++.h>
using namespace std;
int n,q,a[200010],a1[200010],b[200010];
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		for(int j=0;j<=s1.size();j++){
			if(s1[j]=='b'){
				a[i]=j+1;
				a1[i]=s1.size()-a[i];
				break;
			}
		}for(int j=0;j<=s2.size();j++){
			if(s2[j]=='b'){
				b[i]=j+1;
				break;
			}
		}
	}
	while(q--){
		int l,r,ans=0;
		cin>>s1>>s2;
		for(int j=0;j<=s1.size();j++){
			if(s1[j]=='b'){
				l=j+1;
				break;
			}
		}for(int j=0;j<=s2.size();j++){
			if(s2[j]=='b'){
				r=j+1;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if((b[i]-a[i])==(r-l)){
				if(a[i]>l||a1[i]>s1.size()-l)continue;
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

