#include <bits/stdc++.h>
using namespace std;
const int N=200100;
int a[N];
string s[N],ss[N];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i]>>ss[i];
	for(int i=1;i<=n;i++){
		int l,r;
		for(int j=0;j<=s[i].size()-1;j++){
			if(s[i][j]=='b') l=j;
			if(ss[i][j]=='b') r=j;
		}
		a[i]=r-l;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){cout<<0<<endl;continue;}
		int l,r;
		for(int j=0;j<=x.size()-1;j++){
			if(x[j]=='b') l=j;
			if(y[j]=='b') r=j;
		}
		int p=r-l,ans=0;
		for(int j=1;j<=n;j++){
			if(a[j]==r-l){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
