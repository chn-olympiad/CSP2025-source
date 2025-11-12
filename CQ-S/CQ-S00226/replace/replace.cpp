#include <bits/stdc++.h>
using namespace std;
int n,q;
const int M=1e4+5;
string s1[M],s2[M];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		int len1=t1.size();
		int len2=t2.size();
		t1=" "+t1;
		t2=" "+t2;
		for(int i=1;i<=len1;i++){
			for(int j=i+1;j<=len1;j++){
				string t=t1.substr(i,j-i+1);
				for(int kk=1;kk<=n;kk++){
					if(t==s1[kk]){
						string temp=t1.substr(1,i-1);
						temp+=s2[kk];
						temp+=t1.substr(j+1);
						temp=" "+temp;
						if(temp==t2){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
