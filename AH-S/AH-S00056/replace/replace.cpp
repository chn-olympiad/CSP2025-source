#include <bits/stdc++.h>
using namespace std;
string s1[1002],s2[1002];
map <string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	//string sss="abcdef";
	//string ss=sss.replace (2,3,"12");
	//cout<<ss<<endl;
	int n,q;
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		//cout<<s1[i]<<" "<<s2[i]<<endl;
		mp[s1[i]]=s2[i];
	}
	//cout<<1<<endl;
	while (q--){
		int ans=0;
		string t1;
		string t2;
		cin>>t1>>t2;
		int n1=t1.size ();
		for (int i=0;i<n1;i++){
			for (int j=i;j<n1;j++){
				string s3=t1.substr (i,j-i+1);
			//	cout<<s3<<endl;
				if (mp[s3]!="") {
					string tt=t1;
					string s4=tt.replace (i,j-i+1,mp[s3]);
				//	cout<<s4<<endl;
					if (s4==t2) ans++;
				} 
			}
		}
	//	cout<<mp["bc"]<<endl;
		for (int i=1;i<=n;i++){
			mp[s1[i]]="";
		}
		cout<<ans<<endl;
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

2 1
xabcx xadex
bc de
xabcx xadex
*/
