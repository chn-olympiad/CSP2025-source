//GZ-S00399 贵阳市第一中学 薛子彦
#include<iostream>
#include<cstring>
using namespace std;
string s[200010][2],t[200010][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++) cin>>t[i][0]>>t[i][1];
	//a=a.substr(0,a.find(b))+b+a.substr(a.find(b)+b.length(),a.length()-b.length());
	for(int i=1;i<=q;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(t[i][0].find(s[j][0])<1e9 && t[i][1].find(s[j][1])<1e9 && 
			t[i][0].substr(0,t[i][0].find(s[j][0]))+s[j][1]
			+t[i][0].substr(t[i][0].find(s[j][0])+s[j][0].length(),
			t[i][0].length()-s[j][0].length())==t[i][1]){
				cnt++;
			}
			/*
			cout<<t[i][0].substr(0,t[i][0].find(s[j][0]))<<' '<<
			t[i][0].substr(t[i][0].find(s[j][0])+s[j][0].length(),t[i][0].length()-s[j][0].length())<<' '<<
			t[i][0]<<' '<<t[i][1]<<' '<<s[j][0]<<' '<<s[j][1]<<' '<<t[i][0].find(s[j][0])<<endl;
			*/
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*
2 1
xabcx xadex
bc de
xabcx xadex

*/
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
