#include<bits/stdc++.h>
using namespace std;
string s1[200001],s2[200001];
string s1cha[200001],s2cha[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	bool fBpd=1;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=n;i++){
		int l,r1,r2;
		for(int j=0;j<max(s1[i].size(),s2[i].size());j++){
			if(s1[i][j]!=s2[i][j]){
				l=j;
				break;
			}
		}
		int k=s2[i].size()-1;
		for(int j=s1[i].size()-1;j>=0&&k>=0;j--,k--){
			if(s1[i][j]!=s2[i][k]){
				r1=j;
				r2=k;
				break;
			}
		}
		for(int j=l;j<=r1;j++){
			s1cha[i]+=s1[i][j];
		}
		for(int j=l;j<=r2;j++){
			s2cha[i]+=s2[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		s1[i]=s1cha[i];
		s2[i]=s2cha[i]; 
	}
	while(q--){
		string x,y;
		int ans=0;
		cin>>x>>y;
		for(int i=0;i<max(x.size(),y.size());i++){
			if(x[i]!=y[i]){
				for(int j=1;j<=n;j++){
					string xins="";
					for(int k=i;k<i+s1[j].size();k++){
						xins+=x[k];
					}
					if(xins==s1[j]){
						string xins2="";
						for(int k=0;k<i;k++){
							xins2+=x[k];
						}
						xins2+=s2[j];
						for(int k=i+s1[j].size();k<x.size();k++){
							xins2+=x[k];
						}
						if(xins2==y){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//Ren5Jie4Di4Ling5%

