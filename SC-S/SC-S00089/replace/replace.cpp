#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,p;
string s[N][2],t[N][2]; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=p;i++){
		cin>>t[i][0]>>t[i][1];
	}
	for(int i=1;i<=p;i++){
		int ans=0;
		int c=t[i][0].find('b');
		int d=t[i][1].find('b');
		for(int j=1;j<=n;j++){
			int e=s[j][0].find('b');
			int f=s[j][1].find('b');
			if(c-d==e-f && t[i][0].size()-1-c>=s[i][0].size()-1-e && c>=e && d>=f) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}