#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[1005],b[1005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		string s,ss;
		cin>>s>>ss;
		int ans=0;
		for(int j=0;j<s.size();j++){
			string str,strr;
			for(int k=j;k<s.size();k++){
				bool flag=0;
				str+=s[k],strr+=ss[k];
				for(int p=0;p<j;p++){
					if(s[p]!=ss[p]) flag=1;
				}
				for(int p=k+1;p<s.size();p++){
					if(s[p]!=ss[p]) flag=1;
				}
				for(int p=1;p<=n;p++){
					if(a[p]==str && b[p]==strr && flag==0)ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}

