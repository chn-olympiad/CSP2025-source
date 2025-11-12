#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string a[N][2];
string s[N][2];
map<string,string> p;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1];
	for (int i=1;i<=q;i++) cin>>s[i][0]>>s[i][1];
	for (int i=1;i<=n;i++){
		string a_2[2]="";
		for (int j=0;j<a[i][0].size();j++){
			if (a[i][0][j]!=a[i][1][j]){
				a_2[0]+=a[i][0][j];
				a_2[1]+=a[i][1][j];
			}
		}
		a[i][0]=a_2[0];
		a[i][1]=a_2[1];
	}
	for (int i=1;i<=q;i++){
		string s_2[2]="";
		for (int j=0;j<s[i][0].size();j++){
			if (s[i][0][j]!=s[i][1][j]){
				s_2[0]+=s[i][0][j];
				s_2[1]+=s[i][1][j];
			}
		}
		s[i][0]=s_2[0];
		s[i][1]=s_2[1];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
