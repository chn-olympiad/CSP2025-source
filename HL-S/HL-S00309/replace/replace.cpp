#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,q;
string s[N][2];
string cha[N][2];
unordered_map<string,string> mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		mp[s[i][0]]=s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>cha[i][0]>>cha[i][1];
	}
	for(int i=1;i<=q;i++){
		int len=cha[i][0].length(),from=-1,to=-1,tot=0;
		for(int j=0;j<len;j++){
			if(from==-1){
				if(cha[i][0][j]!=cha[i][1][j]){
					from=j;
				}
			}
			else{
				if(cha[i][0][j]!=cha[i][1][j]){
					to=j;
				}
			}
		}
		string opt=cha[i][0].substr(from,to-from+1);
		string opt2=cha[i][1].substr(from,to-from+1);
		if(mp[opt]==opt2){
			tot++;
		}
		printf("%d\n",tot);
	}
	return 0;
}
