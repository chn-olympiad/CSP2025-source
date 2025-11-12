#include<bits/stdc++.h>
using namespace std;
string s[2][200000];
int a[3][200000];
int b[3];
string str[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans,m;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[0][i]>>s[1][i];
		m=s[0][i].size();
		for(int j=0;j<m;j++){
			if (s[0][i][j]=='b') {
				a[1][i]=j;
			}
			if (s[1][i][j]=='b') {
				a[2][i]=j;
			}
		}
		a[0][i]=m;
	}
	for(int i=0;i<q;i++){
		cin>>str[0]>>str[1];
		m=str[0].size();
		ans=0;
		for(int j=0;j<m;j++){
			if (str[0][j]=='b') {
				b[1]=j;
			}if (str[1][j]=='b') {
				b[2]=j;
			}
		}
		for(int i=0;i<n;i++){
			if ((a[2][i]-a[1][i]==b[2]-b[1])&& (a[1][i]<=b[1]) &&(a[0][i]-a[1][i]<=m-b[1]))
				ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}
