//GZ-S00497 遵义市第四中学 马昭懿
#include<bits/stdc++.h>
using namespace std;

int n,q;
int main(){
	freopen("replace","r",stdin);
	freopen("replace","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string s,s2;
		cin>>s>>s2;
	}for(int i=1;i<=q;i++){
		string s,s2;
		int ans=0;
		cin>>s>>s2;
		for(int j=1;j<=s.size();j++){
			if(s[j]==s2[j]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

