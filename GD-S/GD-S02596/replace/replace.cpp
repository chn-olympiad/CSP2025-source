#include<bits/stdc++.h>
using namespace std;
string s1,s2,c[202000][2];
int n,m,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i][0]>>c[i][1];
	}
	for(int i=1;i<=m;i++){
		cin>>s1>>s2;ans=0;
		for(int j=1;j<=n;j++){
			unsigned long long x=s1.find(c[j][0]),y=s2.find(c[j][1]);
			string s3=s1,s4=s2;
			if(x!=18446744073709551615&&y!=18446744073709551615){
				if(x==y){
					for(int i=x;i<x+c[j][0].size();i++){
						s3[i]=c[j][1][i-x];
					}
                    if(s3==s4)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
