#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ans;
string s1[N],s2[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2,ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<t1.length();j++){
				if(t1[j]==s1[i][0]){
					bool flag=1;
					for(int k=0;k<s1[i].length();k++){
						for(int l=j;l<=j+s1[i].length()-1;l++){
							if(t1[l]!=s1[i][k]){flag=0;break;}
						}if(!flag)break;
					}if(flag){
						for(int k=0;k<s1[i].length();k++)for(int l=j;l<=j+s1[i].length()-1;l++)t1[l]=s2[i][k];
						if(t1==t2)ans++;
					}
				}
			}
		}cout<<ans<<"\n";
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
