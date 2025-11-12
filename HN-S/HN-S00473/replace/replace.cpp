#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[20005],s2[20005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int m=t1.size(),ansi=0;
		for(int j=0;j<m;j++){
			int flagj=1;
			for(int k=0;k<j;k++){
				if(t1[i]!=t2[i]){
					flagj=0;
					break;
				}
			}
			if(flagj){
				for(int k=1;k<=n;k++){
					int flagk=1;
					for(int l=0;l<s1[k].size();l++){
						if(j+l>=m||t1[j+l]!=s1[k][l]||t2[j+l]!=s2[k][l]){
							flagk=0;
							break;
						}
					}
					if(flagk){
						int flagl=1;
						for(int l=0;l<m;l++){
							if(t1[j+s1[k].size()+l]!=t2[j+s1[k].size()+l]){
								flagl=0;
								break;
							}
						}
						ansi+=flagl;
					}
				}
			}
		}
		cout<<ansi<<endl;
	}
	return 0;
}
