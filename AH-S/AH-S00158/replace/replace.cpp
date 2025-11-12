//7.07 14.22 7.01 14.15  '11.15'    
#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200010][12];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s1.find(s[i][1])&&s2.find(s[i][2])){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
