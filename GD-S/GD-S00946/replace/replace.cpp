#include<bits/stdc++.h>
using namespace std;
void op(){
	freopen("replace1.in","r",stdin);
	freopen("replace.out","w",stdout);
}
string s[10005],s1[10006],s2,s3;
int n,m;
int main(){
	op();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
	}
	while(m--){
		cin>>s2>>s3;
		int ans=0;
		for(int i=1;i<=n;i++){
			int f=s2.find(s[i]),p=0;
			if(f!=-1){
				for(int j=0;j<f;j++){
					if(s2[j]!=s3[j]){
						p=1;
						break;
					}
				}
				if(p==1)continue;
				for(int j=f;j<f+s1[i].size();j++){
					if(s1[i][j-f]!=s3[j]){
						p=1;
						break;
					}
				}
				if(p==1)continue;
				for(int j=f+s2.size()+1;j<s3.size();j++){
					if(s2[j]!=s3[j]){
						p=1;
						break;
					}
				}
				if(!p)ans++;
			}
			
		}
		cout<<ans<<"\n"; 
	}
}
