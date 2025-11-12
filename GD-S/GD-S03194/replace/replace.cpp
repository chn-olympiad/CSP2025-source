#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string a[1001],b[1001],s1,s2;
void solve(){
	while(q--){
		ans=0;
		cin>>s1>>s2; 
		for(int i=1;i<=n;i++){
			if(a[i].size()<=s1.size()){
				for(int j=0;j<=s1.size()-a[i].size();j++){
					bool flag=1;
					for(int k=0;k<a[i].size();k++){
						if(b[i][k]!=s2[j+k]||a[i][k]!=s1[j+k]){
							flag=0;
							break;
						}
					}
					if(flag){
						bool flag2=1;
						for(int k=0;k<j;k++){
							if(s1[k]!=s2[k]){
								flag2=0;
								break;
							}
						}
						if(flag2){
							bool flag3=1;
							for(int k=j+a[i].size();k<s1.size();k++){
								if(s1[k]!=s2[k]){
									flag3=0;
									break;
								}
							}
							if(flag3){
								ans++;
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
void solve2(){
	while(q--){
		cout<<0<<endl;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(n<=100){
		solve();
	}
	else{
		solve2();
	}
	return 0;
}
