//GZ-S00264 YangChengjin HLXX
#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[5000005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(q--){
		string a,b,ts;
		int cnt=0;
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			ts=a;
			int pos=a.find(s[i][0]);
			if(pos>=0){
				for(int j=pos;j<pos+s[i][0].length();j++) {
					ts[j]=s[i][1][j-pos];
				}
			}
			if(ts==b)cnt++;	
		}
		cout<<cnt<<'\n';
	}
	return 0;//by-ycj
}
/*

xabcx xadex
01234 01234

bc de
01 01


4 2

xabcx xadex

ab cd

bc de

aa bb

xabcx xadex

aaaa bbbb

*/
