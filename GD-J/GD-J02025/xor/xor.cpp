#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500050];
int cd=0;
string s[500050],sk,ans;
int maxx(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int dx=a[i];
		if(a[i]==0) s[i]='0';
		while(dx>0){
			s[i]+=(char)(dx%2+'0');
			dx/=2;
			cd=maxx(cd,s[i].size());
		}
		for(int j=0;j<s[i].size()/2;j++) swap(s[i][j],s[i][s[i].size()-1-j]);
	}
	for(int i=1;i<=n;i++){
		if(s[i].size()<cd){
			for(int j=0;j<cd-s[i].size();j++){
				s[i]='0'+s[i];
			}
		}
	}
	for(int i=0;i<cd;i++){
		if(s[1][i]!=s[2][i]){
			cout<<0<<"\n";
			return 0;
		}
	}
	if(a[1]==a[2]&&a[1]==0) cout<<2<<"\n";
	else cout<<1<<"\n";
}
