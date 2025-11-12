#include<bits/stdc++.h>
using namespace std;
int n,q,t[200010],k,kk,ans;
string s[200010][3],t_1,t_2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		for(int j=0;j<s[i][1].length();j++)
			if(s[i][1][j]=='b'){
				k=j;
				break;
			}
		for(int j=0;j<t_2.length();j++)
			if(s[i][2][j]=='b'){
				t[i]=j-k;
				break;
			}
	}
	while(q--){
		cin>>t_1>>t_2;
		int len=t_1.length();
		for(int i=0;i<t_1.length();i++)
			if(t_1[i]=='b'){
				k=i;
				break;
			}
		for(int i=0;i<t_2.length();i++)
			if(t_2[i]=='b'){
				k=i-k;
				break;
			}
		ans=0;
		for(int i=1;i<=n;i++){
			if(s[i][1].length()>len)continue;
			if(k==t[i]) ans++;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
