#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string s1[500001],s2[500001];
bool ca(string a,string b,string c,string d){
	for(int i=0;i<a.size();i++){
		bool fl=0;
		for(int j=0;j<c.size();j++){
			if(a[i+j]!=c[j]){
				fl=1;
				break;
			}
		}
		if(!fl){
			string tp=a;
			for(int j=0;j<c.size();j++)
				a[i+j]=d[j];
			bool fl1=0;
			for(int i=0;i<a.size();i++){
				if(a[i]!=b[i]){
					fl1=1;
					break;
				}
			}
			if(!fl1)return true;
			a=tp;
		}
	}
	return false;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		string x,y;cin>>x>>y;
		int an=0,l=0,r=0;
		for(int i=1;i<=n;i++){
			an+=ca(x,y,s1[i],s2[i]);
		}
		cout<<an<<'\n';
	}
	return 0;
}