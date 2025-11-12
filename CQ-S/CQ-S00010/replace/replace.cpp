#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
const int inf=0x3f3f3f3f;
inline int read(){
	char ch=getchar();
	int f=1,s=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	}
	return f*s;
} 
int n,q;
string s[N][3],t[3];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t[1]>>t[2];
		int l=t[1].size(),cnt=0;
		if(l!=t[2].size())printf("0\n");
		else {
			int L=0,R=0,f=0;
			string s1="",s2="";
			for(int j=0;j<l;j++){
				if(t[1][j]!=t[2][j]&&(f==0)){
					L=j;
					f=1;
				}
				if(t[1][j]==t[2][j]&&(f==1)){
					R=j;
					break;
				}
				if(j>=L&&f){
					s1+=(t[1][j]);
					s2+=(t[2][j]);
				}
			}
			for(int i=1;i<=n;i++){
				bool f=0;
				if(s[i][1].find(s1)<=n){
					if(s[i][1]==s1){
				//		cout<<s[i][2]<<" "<<s2<<"\n";
						if(s[i][2]==s2)cnt++;
						else f=1;
					}
					else {
						for(int j=0;j<s[i][1].size();j++){
							if(s[i][1][j]==s1[0]){
								string ss1="",ss2="";
								for(int k=0;k<=(R-L+1);k++){
									ss1+=s[i][1][j+k];
									ss2+=s[i][2][j+k];
								}
								if(ss1!=s1||ss2!=s2){
									f=1;
									break;
								}
							}
						}
					}
					if(!f)cnt++;
				}
				
			}
			printf("%lld\n",cnt);
		}
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
