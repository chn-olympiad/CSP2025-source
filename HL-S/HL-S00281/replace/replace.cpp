#include<iostream>
#include<string.h>
using namespace std;
string s[200010][2];
string y[200010][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=0;i<q;i++){
		cin>>y[i][0]>>y[i][1];
	}
	for(int i=0;i<q;i++){
		int ans=0;
		for(int j=0;j<n;j++){
			if(y[i][0].find(s[j][0])!=string::npos){
				int ns=y[i][0].find(s[j][0])-1;
				string u=y[i][0].substr(0,ns+1)+s[j][1]+y[i][0].substr(s[j][1].size()+ns+1);
				if(u==y[i][1]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
