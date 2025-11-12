#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200010],s2[200010];
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>a>>b;
		string A,B;
		A=a;B=b;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0,ek=0;j<a.size();j++){
				ek=0;
				if(a[j]==s1[i][ek]){
					int pj=j;
					while(a[pj]==s1[i][ek]){
						a[pj]=s2[i][ek];
						ek++;pj++;
						if(ek==s1[i].size()||pj==a.size()){
							break;
						}
					}
					if(ek==s1[i].size()){
						if(a==b){
							ans++;
						}
				}
				a=A;
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
}
/*
3 1
xabcx xadex
bc de
aa bb
xabcx xadex
*/
