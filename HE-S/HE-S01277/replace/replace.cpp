#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int n,q;
string s[N][2],t[N][2];
int check(string s1,string t1){
	int l=s1.size(),l1=t1.size(),f=1;
	for(int i=0;i<l1-l;i++){
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=t1[j+i]){
				f=0;
				break;
			}
		}
		if(f==1) return 1;
	}return 0;
}
/*4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb*/
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		int ans=0;
		for(int j=1;j<=n;j++){
			if(check(s[j][0],t[i][0])&&check(s[j][1],t[i][1])){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

