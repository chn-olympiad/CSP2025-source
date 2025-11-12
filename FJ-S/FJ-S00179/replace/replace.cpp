#include<bits/stdc++.h>
using namespace std;
int n,q,z;
string s1[200005],s2[200005],t1,t2,s;
bool g;
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		z=0;
		for(int i=1;i<=n;++i){
			for(int k=0;k<=t1.size();++k){
				if(t1[k]==s1[i][0]){
					g=1;
					for(int j=0;j<s1[i].size();++j){
						if(t1[k+j]!=s1[i][j]){
							g=0;
							for(int l=0;l<j;++l)
								t1[k+l]=s[l];
							break;
						}else{
							s[j]=t1[k+j];
							t1[k+j]=s2[i][j];
						}	
					}
					if(g==1){
						if(t1==t2){
							++z;
							for(int l=0;l<s1[i].size();++l)
								t1[k+l]=s[l];
						}	
						break;
					}
				}
			}
		}
		cout<<z<<"\n";
	}
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
