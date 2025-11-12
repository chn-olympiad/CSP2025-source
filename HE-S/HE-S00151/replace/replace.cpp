#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][4];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1];
		cin>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string a,b;
		cin>>a>>b;
		
		for(int j=1;j<=n;j++){
			string c=a;
			int cnt1=0,cnt2=0,flag=0;
			//cout<<s[j][1]<<" "<<s[j][2]<<endl;
			for(int k=0;k<c.length();k++){
				cnt1=0;
				//cout<<s[j][1][cnt1]<<" "<<a[k]<<endl;
				while(s[j][1][cnt1]==c[k]){
					//cout<<s[j][1][cnt1]<<" "<<a[k]<<endl;
					if(cnt1==s[j][1].length()-1){
						//cout<<k-cnt1<<" "<<k<<endl;
						for(int u=k-cnt1;u<=k;u++){
							c[u]=s[j][2][u];
						}
						if(c==b){
							ans++;
							break;
						}
						flag=1;
						break;
					}
					cnt1++;
					k++;
				}
			}
		}
		cout<<ans<<endl;
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
