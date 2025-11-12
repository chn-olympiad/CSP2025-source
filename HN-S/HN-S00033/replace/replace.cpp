#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005],t[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i]>>t[i];
	while(q--){
		string a,b;
		int sum=0;
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			string l=a;
			for(int j=0;j<a.size();j++){
				bool f=1;
				for(int k=0;k<s[i].size();k++){
					if(s[i][k]!=a[j+k]){
						f=0;
						break;
					}
					a[j+k]=t[i][k];
				}
				if(f&&a==b)sum++;
				a=l;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}

