#include<bits/stdc++.h>
using namespace std;
string s[600][5];
string k[5];
int n,q,ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++){
		cin>>k[1]>>k[2];
		if(k[1].size()!=k[2].size()){
			cout<<"0";
			continue;
		}
		int mk=k[1].size();
		for(int pp=1;pp<=mk;pp++){
			string u="";int pu=0;
			for(int o=1;o<=pp-1;o++)if(k[1][o-1]!=k[2][o-1]){
				pu=1;
				break;
			}
			if(pu==1)break; 
			for(int o=pp;o<=mk;o++){
				u=u+k[1][o-1];
				for(int p=1;p<=n;p++){
					if(u==s[p][1]){
//						cout<<pp<<' '<<o<<' '<<u<<endl;
						int pu=0,pl=0;
						for(int j=pp;j<=o;j++){
							pl++;
							if(s[p][2][pl-1]!=k[2][j-1]){
//							cout<<"#"<<s[p][2][j-1]<<' '<<k[2][j-1]<<endl;
							pu=1;
							break;
						}
						}
						for(int j=o+1;j<=mk;j++)if(k[1][j-1]!=k[2][j-1]){
//							cout<<"#"<<k[1][j-1]<<' '<<k[2][j-1]<<endl;
							pu=1;
							break;
						}
						if(pu==0)ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
			ans=0;
	}
	return 0;
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
