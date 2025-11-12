#include<bits/stdc++.h>
using namespace std;
string s[1000][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		int cnt=0;
		string a,b,a2;
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			auto t=a.find(s[i][0]);
			if(t!=-1){
				a2=a;
				for(int j=t;j<t+s[i][0].length();j++){
					a2[j]=s[i][1][j-t];
				}
				if(a2==b){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
