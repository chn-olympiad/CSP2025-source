#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[200005],b[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++){
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<0<<endl;
			continue;
		}
		int cnt=0;
		for(int j=1;j<=n;j++){
			int pos=0,f=0;
			for(int k=0;k<s.size();k++){
				if(f==1&&s[k]!=t[k])	f=0;
				if(s[k]==a[j][pos]&&t[k]==b[j][pos]){
					pos++;
					if(pos==a[j].size()){
						f=1;
					}
				}
				else
				{
					pos=0;
				}
			}
			if(f)	cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
