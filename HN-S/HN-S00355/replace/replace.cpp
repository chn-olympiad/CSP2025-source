#include<bits/stdc++.h>
using namespace std;
#define N 100010
int u,n,q;
string s[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("repalce.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		string s1,s2;
		int f=0;
		cin>>s1>>s2;
		for(int i=0;i<s1.size();i++){
			if(f) break;
			for(int j=1;j<=n;j++){
				if(f) break;
				int flag=1;
				for(int k=0;k<s[j][2].size();k++){
					if(s2[i+k]!=s[j][2][k]) flag=0;
				}
				for(int k=0;k<s[j][1].size();k++){
					if(s1[i+k]!=s[j][1][k]) flag=0;
				}
				for(int k=0;k<s[j][2].size();k++){
					if(s2[i+k]!=s1[i+k]) flag=0;
				}
				if(flag){
//					cout<<0<<endl;
					f=1;
				}
			}
		}
		cout<<0<<endl;
	}
	return 0;
}

