#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int k=1;k<=n;k++){
			int len=s[k][1].size();
			for(int j=0;j<a.size()-len+1;j++){
				if(a.substr(j,len)==s[k][1]){
					string y=a.substr(0,j)+s[k][2]+a.substr(j+len,a.size()-(j+len)+1);
					if(y==b)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
