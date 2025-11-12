#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
string s[MAXN][2],t[MAXN][2],src[MAXN];
string rc(string x,string y){
	string ch="",pch="";
	bool sr=false;
	for(int i=0;i<x.size();i++){
		if(sr)pch+=y[i];
		if(x[i]!=y[i]){
			if(ch==""){
				ch+=y[i];
				sr=true;
			}
			else{
				ch+=pch;
				pch="";
			}
		}
	}
	return ch;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s[i][0] >> s[i][1];
		src[i]=rc(s[i][0],s[i][1]);
	}
	for(int i=1;i<=q;i++){
		cin >> t[i][0] >> t[i][1];
		int th=0;
		string trc=rc(t[i][0],t[i][1]);
		for(int j=1;j<=n;j++){
			if(src[j]==trc){
				bool cc=false;
				for(int k=0;k<t[i][0].size();k++){
					if(t[i][0][k]==s[j][0][0]){
						cc=true;
						for(int l=0;l<s[j][0].size();l++){
							if(k+l>=t[i][0].size()||s[j][0][l]!=t[i][0][k+l]){
								cc=false;
								break;
							}
						}
					}
				}
				if(cc)th++;
			}
		}
		cout << th << endl;
	}
	return 0;
}
